---
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
title: What is MQTT
---

<em class="text-5xl">
MQTT [...] is designed as an extremely lightweight <code class="underline underline-[#DDF286]">publish/subscribe</code> messaging transport that is ideal for connecting remote devices with a small code footprint [...]
</em>

<cite><a href="https://mqtt.org" target="_blank">mqtt.org</a></cite>


---
level: 2
title: sequence diagram pub/sub
layout: fact
preload: true
transition: fade
---

```mermaid
sequenceDiagram
  participant Publisher
  participant MQTT Broker
  participant Subscriber
  participant Other subscriber

  Subscriber->>MQTT Broker: Subscribe
  Other subscriber->>MQTT Broker: Subscribe
  Publisher->>+MQTT Broker: Publish message
  MQTT Broker->>Subscriber: Deliver message
  MQTT Broker->>-Other subscriber: Deliver message
```

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
    background-color: #D5EEF4;
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
level: 2
title: sequence diagram arduino
layout: fact
preload: true
transition: slide-left
---

```mermaid
sequenceDiagram
  participant Website
  participant MDD-tardis
  participant Arduino
  participant Fridge

  Arduino->>MDD-tardis: Subscribe
  Fridge->>MDD-tardis: Subscribe
  Website->>+MDD-tardis: Publish message
  MDD-tardis->>Arduino: Deliver message
  MDD-tardis->>-Fridge: Deliver message
```

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
    background-color: #D5EEF4;
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
level: 2
title: MQTT client
image: ./mqtt-online.png
layout: image
transition: fade
---

<div class="flex items-end justify-center h-full text-4xl">
<span class="px-1 py-3 bg-[#193F52]">
<a target="_blank" href="http://www.emqx.io/online-mqtt-client">emqx.io/online-mqtt-client</a>
</span>
</div>

---
level: 2
title: MQTT Explorer details
image: ./mqtt-online-topic.png
layout: image
transition: slide-left
---

---
title: Topics
layout: fact
---

<section>
<div class="text-7xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2024</div>
</section>

<section v-click>
<div class="text-3xl absolute top-64 opacity-25">topic</div>
<arrow x1="140" y1="275" x2="850" y2="275" color="#D5EEF4" width="2" class="opacity-15" />
</section>

<section v-click>
<div class="text-3xl absolute top-15 left-105 italic">topic level</div>
<arrow x1="300" y1="130" x2="300" y2="230" color="#D5EEF4" width="2" />
<arrow x1="490" y1="130" x2="490" y2="230" color="#D5EEF4" width="2" />
<arrow x1="690" y1="130" x2="690" y2="230" color="#D5EEF4" width="2" />
</section>

<section v-click>
<div class="text-3xl absolute top-110 left-87 italic text-[#DDF286]">topic level separator</div>
<arrow x1="395" y1="410" x2="395" y2="320" color="#DDF286" width="2" />
<arrow x1="580" y1="410" x2="580" y2="320" color="#DDF286" width="2" />
</section>

---
title: Wildcard - multi level
level: 2
layout: fact
transition: fade
---

<section class="flex">
  <div class="text-7xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>#</div>

  <section>
  <div class="text-xl absolute top-10 left-155 opacity-25">only at the end</div>
  <arrow x1="510" y1="90" x2="600" y2="60" color="#D5EEF4" width="2" class="opacity-15" />

  <div class="text-xl absolute top-33 left-155 opacity-25">matches everything after</div>
  <arrow x1="510" y1="110" x2="600" y2="140" color="#D5EEF4" width="2" class="opacity-15" />
  </section>
</section>

<section class="flex gap-8 flex-col mt-30">
  <div class="flex gap-4 items-center">
    ✅
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2023</div>
  </div>
  <div class="flex gap-4 items-center">
    ✅
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2024</div>
  </div>
  <div class="flex gap-4 items-center">
    ✅
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2024<span class="text-[#DDF286]">/</span>grades</div>
  </div>
  <div class="flex gap-4 items-center">
    🚫
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>staff<span class="text-[#DDF286]">/</span>2024</div>
  </div>
</section>

---
title: Wildcard - single level
level: 2
layout: fact
---

<section class="flex">
  <div class="text-7xl">MDD<span class="text-[#DDF286]">/</span>+<span class="text-[#DDF286]">/</span>2024</div>
  <section>
  <div class="text-xl absolute top-10 left-155 opacity-25">one level, can be at the end</div>
  <arrow x1="510" y1="90" x2="600" y2="60" color="#D5EEF4" width="2" class="opacity-15" />

  <div class="text-xl absolute top-33 left-155 opacity-25">does not match everything after</div>
  <arrow x1="510" y1="110" x2="600" y2="140" color="#D5EEF4" width="2" class="opacity-15" />
  </section>
</section>

<section class="flex gap-8 flex-col mt-30">
  <div class="flex gap-4 items-center">
    🚫
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2023</div>
  </div>
  <div class="flex gap-4 items-center">
    ✅
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2024</div>
  </div>
  <div class="flex gap-4 items-center">
    🚫
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>class<span class="text-[#DDF286]">/</span>2024<span class="text-[#DDF286]">/</span>grades</div>
  </div>
  <div class="flex gap-4 items-center">
    ✅
    <div class="text-2xl">MDD<span class="text-[#DDF286]">/</span>staff<span class="text-[#DDF286]">/</span>2024</div>
  </div>
</section>

---
title: Demo using mdd-tardis.net
layout: iframe-right
url: http://mdd-tardis.net:8081
preload: true
---

<div class="flex h-full items-center justify-center">
<MqttButton />
</div>

<style>
  .slidev-page {
    grid-template-columns: 1fr 6fr;
  }

  .slidev-page.slidev-layout {
    padding: 0;
    display: flex;
    justify-content: center;
    align-items: center;
  }
</style>


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
#include <MQTT.h>
WiFiClient net;
MQTTClient client;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin("iotroam", "loislane");
  client.begin("mdd-tardis.net", net);
  client.onMessage(messageReceived);
}
void connect() {
  while (WiFi.status() != WL_CONNECTED) {delay(100);}
  while (!client.connect("id", "mdd", "loislane")) {delay(100);}
  client.subscribe("topic");
  client.publish("topic", "Hello from arduino");
}
void messageReceived(String &topic, String &message) {
  Serial.println(topic + ": " + message);
}
void loop() {
  client.loop(); delay(10);
  digitalWrite(LED_BUILTIN, client.connected()); // Status LED
  if (!client.connected()) { connect(); }
}
```

</template>
<template v-slot:right>

**HTML***

```html
<body>
  <script src="https://unpkg.com/mqtt/dist/mqtt.js"></script>
  <script>
    const client = mqtt.connect("mqtts://mdd-tardis.net", {
      clientId: "id",
      username: "mdd",
      password: "loislane",
      port: 9001
    })
    client.on("message", messageReceived);
    client.on("connect", function() {
      println("connected!");
      client.subscribe("topic");
      client.publish("topic", "Hello from HTML");
    });

    function messageReceived(topic, message) {
      println(topic + ": " + message);
    }
    function println(message) {
      const p = document.createElement("p");
      p.textContent = message;
      document.querySelector("body").prepend(p);
    }
  </script>
</body>
```

<span class="text-xs">
* All examples are based on these starter codes
</span>

</template>

<style>
  .slidev-layout {
    padding: 0.25rem 0.5rem;
    grid-template-columns: 1fr 1fr;
    gap: 0.5rem;
  }

  .slidev-layout p {
   margin: 0.25rem;
  }

  code {
    font-size: 0.8em;
  }
</style>

---
level: 2
title: Basic
layout: center
---

## Basic example

<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt" class="text-4xl">
  xiduzo.github.io/presentation-mqtt
</a>

---
level: 2
title: Chat
layout: center
---

## Real time chat

<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/chat" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/chat
</a>

---
level: 2
title: Cursor
layout: center
---

## Collaboration cursor

<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/cursor" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/cursor
</a>

---
level: 2
title: Lights
layout: center
transition: slide-left
---

## Smart lights
<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/light" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/light
</a>

---
layout: cover

---

# DIY

Make two _things_ talk to each other using MQTT

https://shiftr.io/docs/manuals <br/>
https://dlo.mijnhva.nl/d2l/le/content/557321/Home

---
layout: cover
level: 2
---

## Starter advice

1. For now, use HTML/CSS/JavaScript. Try the arduino later!
2. Split the workload, one person will be _publishing_ and the other _subscribing_
