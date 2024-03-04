---
background: https://mqtt.org/assets/img/homepage-gradient.jpg
title: MQTT
transition: slide-up
hideInToc: true
---

# MQTT

Make _things_ talk with each other

<time datetime="2024-03-20">_20th March 2024_</time>


---
level: 2
transition: slide-left
layout: center
---

# Today

<Toc maxDepth="1"></Toc>


---
layout: fact
title: What is MQTT?
---

<em class="text-5xl">
MQTT [...] is designed as an extremely lightweight <code class="underline underline-[#1BAA54]">publish/subscribe</code> messaging transport that is ideal for connecting remote devices with a small code footprint [...]
</em>

<cite>https://mqtt.org</cite>


---
level: 2
title: sequence diagram
layout: fact
preload: true
clicks: 1
---

<span v-click.hide="1">
```mermaid
sequenceDiagram
  participant Publisher
  participant MQTT Broker
  participant Subscriber
  participant Subscriber 2

  Subscriber->>MQTT Broker: Subscribe
  Subscriber 2->>MQTT Broker: Subscribe
  Publisher->>+MQTT Broker: Publish message
  MQTT Broker->>Subscriber: Deliver message
  MQTT Broker->>-Subscriber 2: Deliver message
```
</span>

<span v-click="1">
```mermaid
sequenceDiagram
  participant Arduino
  participant Shiftr
  participant Website
  participant TouchDesigner

  Website->>Shiftr: Subscribe
  TouchDesigner->>Shiftr: Subscribe
  Arduino->>+Shiftr: Publish message
  Shiftr->>Website: Deliver message
  Shiftr->>-TouchDesigner: Deliver message
```
</span>

<div class="animated-dot one"></div>
<div class="animated-dot two"></div>

<style>
  .slidev-vclick-target {
    transition: all 500ms ease;
  }

  .slidev-vclick-hidden {
    transform: scale(0);
    display: none;
  }

  @keyframes moveDotOne {
    0% {
      transform: translateX(127px) translateY(-220px);
      opacity: 1;
    }
    30% {
      transform: translateX(327px) translateY(-220px);
      opacity: 1;
    }
    60% {
      transform: translateX(327px) translateY(-166px);
      opacity: 1;
    }
    90% {
      transform: translateX(527px) translateY(-166px);
      opacity: 1;
    }
    95% {
      transform: translateX(527px) translateY(-166px);
      opacity: 0;
    }
    100% {
      transform: translateX(127px) translateY(-166px);
      opacity: 0;
    }
  }

  @keyframes moveDotTwo {
    0% {
      transform: translateX(127px) translateY(-220px);
      opacity: 1;
    }
    30% {
      transform: translateX(327px) translateY(-220px);
      opacity: 1;
    }
    60% {
      transform: translateX(327px) translateY(-111px);
      opacity: 1;
    }
    90% {
      transform: translateX(727px) translateY(-111px);
      opacity: 1;
    }
    95% {
      transform: translateX(727px) translateY(-111px);
      opacity: 0;
    }
    100% {
      transform: translateX(127px) translateY(-111px);
      opacity: 0;
    }
  }

  .animated-dot {
    content: ' ';
    width: 15px;
    height: 15px;
    background-color: #1BAA54;
    border-radius: 50%;
    position: absolute;
    animation-duration: 2s;
    animation-iteration-count: infinite;
  }

  .animated-dot.one {
    animation-name: moveDotOne;
  }

  .animated-dot.two {
    animation-name: moveDotTwo;
  }
</style>


---
title: Demo using shiftr.io
image: ./shiftr.png
layout: image
---

<div class="flex items-end justify-center h-full text-4xl">
  <a href="https://mdd-mqtt-example.cloud.shiftr.io">mdd-mqtt-example.cloud.shiftr.io</a>
</div>

---
level: 2
title: MQTT Explorer
image: ./mqtt-explorer.png
layout: image
transition: slide-left
---

<div class="flex items-end justify-center h-full text-4xl">
  <a href="https://mqtt-explorer.com/">mqtt-explorer.com</a>
</div>

---
title: Examples
layout: fact
---

<div class="text-7xl">MDD<span class="text-[#1BAA54]">/</span>class<span class="text-[#1BAA54]">/</span>2024</div>

<arrow x1="390" y1="410" x2="390" y2="320" color="#1BAA54" width="2" />
<arrow x1="580" y1="410" x2="580" y2="320" color="#1BAA54" width="2" />

<arrow x1="280" y1="130" x2="280" y2="230" color="#fff" width="2" />
<arrow x1="490" y1="130" x2="490" y2="230" color="#fff" width="2" />
<arrow x1="690" y1="130" x2="690" y2="230" color="#fff" width="2" />

<div class="text-3xl absolute top-15 left-105 italic">topic level</div>
<div class="text-3xl absolute top-110 left-88 italic text-[#1BAA54]">topic level separator</div>

---
level: 2
title: MQTT Explorer
image: ./mqtt-topic.png
layout: image
---

---
title: Examples
layout: cover
---

# Examples
https://github.com/xiduzo/presentation-mqtt/tree/main/examples

---
title: Arduino & HTML
level: 2
layout: two-cols
---


<template v-slot:default>

**Arduino***

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient net;
// https://pubsubclient.knolleary.net
PubSubClient client(net);
client.setServer("<server>", "<port>");
client.setCallback(onMessageArrived)

const char* id = String(random(0xffff), HEX);
const char* topic = "<topic>";

void setup() {
  Serial.begin(9600);
  WiFi.begin("<ssid>", "<pass>");
  while (WiFi.status() != WL_CONNECTED) { delay(500); }
  client.connect(id, "<user>", "<pass>");
  client.subscribe(topic);
  client.publish(topic, "Hello from " + id);
}

void loop() { client.loop(); }

void onMessageArrived(char *topic, byte *message) {
  Serial.println("received: " + String((char*)message));
}
```

</template>
<template v-slot:right>

**HTML***

```html
<body>
  <script src="https://unpkg.com/mqtt/dist/mqtt.js"></script>

  <script>
    const id = Math.random().toString(36).substring(7);
    const topic = "<topic>";
    
    // https://www.npmjs.com/package/mqtt
    const client = mqtt.connect("<server>", { clientId: id });

    client.on("connect", function () {
      console.log("connected!");
      client.subscribe(topic);
      client.publish(topic, "Hello from " + id);
    });
    
    client.on("message", function (topic, message) {
      console.log("received '" + message + "' on " + topic);
    })
  </script>
</body>
```

<br/><br/>
\* All examples are based on this starter code
</template>

<style>
  .slidev-layout {
    padding: 0.5rem;
    grid-template-columns: 1fr 1fr;
    gap: 1rem;
  }
</style>

---
level: 2
title: Cursor
layout: center
---

**Figma-y live cursor**

<a href="https://xiduzo.github.io/presentation-mqtt/cursor" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/cursor
</a>

---
level: 2
title: Lights
layout: center
---

**Smart lights**
<!-- This will be a website controlling an arduino LED and arduino light sensor making background -->
<a href="https://xiduzo.github.io/presentation-mqtt/light" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/light
</a>

---
level: 2
title: Unity
layout: center
transition: slide-left
---

**Remote control**
<!-- This will be a website controlling an arduino LED -->
<a href="https://xiduzo.github.io/presentation-mqtt/light" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/light
</a>

---
layout: cover
---

# DIY

Make two _things_ talk to each other using MQTT

https://shiftr.io/docs/manuals <br/>
https://wiki.mdd-tardis.net/index.php/IoT_boilerplate
