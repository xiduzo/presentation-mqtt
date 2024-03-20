---
title: MQTT
transition: slide-up
hideInToc: true
---

# MQTT

A super-efficient postal service for data

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

<em class="text-5xl relative z-1">
MQTT [...] is designed as an extremely lightweight <code class="underline underline-[#DDF286] relative -z-1">publish/subscribe</code> messaging transport that is ideal for connecting remote devices with a small code footprint [...]
</em>

<cite><a href="https://mqtt.org" target="_blank">mqtt.org</a></cite>

---
layout: fact
level: 2
title: ChatGPT on MQTT
---

<em class="text-5xl relative z-1">
Imagine you have a bunch of devices like sensors, smartphones, or computers that need to talk to each other over the internet. MQTT helps them do just that, kind of like a super-efficient postal service for data.
</em>

<cite><a href="https://chat.openai.com/share/37c227f4-83a0-4bca-8a96-e5f5b4bdb84b" target="_blank">ChatGPT</a></cite>


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
  participant mdd-tardis.net
  participant Arduino
  participant Fridge

  Arduino->>mdd-tardis.net: Subscribe
  Fridge->>mdd-tardis.net: Subscribe
  Website->>+mdd-tardis.net: Publish message
  mdd-tardis.net->>Arduino: Deliver message
  mdd-tardis.net->>-Fridge: Deliver message
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
layout: center
---

## Basic connection

<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt" class="text-4xl">
  xiduzo.github.io/presentation-mqtt
</a>

---
level: 2
layout: center
---

## Twitter v0.1

<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/chat" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/chat
</a>

---
level: 2
layout: center
---

## Real time collaboration

<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/cursor" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/cursor
</a>

---
level: 2
layout: center
---

## Democratic color picker
<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/color" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/light
</a>

---
level: 2
layout: center
transition: slide-left
---

## Interactive lunar cycle
<a target="_blank" href="https://xiduzo.github.io/presentation-mqtt/moon" class="text-4xl">
  xiduzo.github.io/presentation-mqtt/moon
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

---
layout: cover
level: 2
---

# Publish examples
https://www.w3schools.com/jsref/dom_obj_event.asp

---
layout: cover
level: 2
---

## Mouse events

```javascript
window.addEventListener("mousemove", (e) => {
  client.publish("mouse", JSON.stringify({x: e.clientX, y: e.clientY}));
});
```
```javascript
window.addEventListener("click", (e) => {
  client.publish("click", "clicked on " + e.target.tagName);
});
```
```javascript
window.addEventListener("mousedown", (e) => {
  client.publish("mousedown", "mouse " + e.button + " down");
});
```
```javascript
window.addEventListener("mouseup", (e) => {
  client.publish("mouseup", "mouse " + e.button + " up");
});
```
```javascript
window.addEventListener("wheel", (e) => {
  client.publish("wheel", JSON.stringify({deltaY: e.deltaY, deltaX: e.deltaX}));
});
```

---
layout: cover
level: 2
---

## Scroll position

```javascript
window.addEventListener("scroll", (e) => {
  client.publish("scroll", window.scrollY);
});
```

---
layout: cover
level: 2
---

## Key press

```javascript
window.addEventListener("keydown", (e) => {
  client.publish("key", e.key);
});
```
```javascript
window.addEventListener("keydown", (e) => {
  if(e.key === "ArrowUp") {
    client.publish("key", "♥️")
  } else if (e.key === "ArrowDown") {
    client.publish("key", "🤖️")
  } else if (e.key === "ArrowLeft") {
    client.publish("key", "🦍")
  } else if (e.key === "ArrowRight") {
    client.publish("key", "🍺")
  }
});
```

---
layout: cover
level: 2
---

## Click event

```javascript
<button>Click me</button>

document.querySelector("button").addEventListener("click", (e) => {
  client.publish("click", "button");
});
```
```javascript
<ul>
  <li>Item 1</li>
  <li>Item 2</li>
  <li>Item 3</li>
</ul>

document.querySelectorAll("li").forEach((li, i) => {
  li.addEventListener("click", (e) => {
    client.publish("click", "clicked on list item " + e.target.textContent);
  });
});
```

---
layout: cover
level: 2
---

## Form events

```javascript
<form>
  <input type="text" placeholder="Type something">
  <button>Submit</button>
<form>

document.querySelector("form").addEventListener("submit", (e) => {
  e.preventDefault();
  client.publish("submit", e.target.querySelector("input").value);
});
```

---
layout: cover
level: 2
---

## On an interval

```javascript
setInterval(() => {
  client.publish("interval", "ping");
}, 1000);
```

---
layout: cover
level: 2
---

# Subscribe examples

---
layout: cover
level: 2
---

## Add an element to the page, or remove it again

```javascript
client.on("message", (topic, message) => {
  const p = document.createElement("p");
  p.textContent = message;
  document.querySelector("body").prepend(p);
});
```
```javascript
client.on("message", (topic, message) => {
  const p = document.querySelector("p");
  p.remove();
})
```

---
layout: cover
level: 2
---

## Change some elements' style
This can be any CSS style!

```javascript
client.on("message", (topic, message) => {
  document.body.style.backgroundColor = message;
});
```
```javascript
client.on("message", (topic, message) => {
  document.querySelector("button").style.borderRadius = message + "px";
});
```
```javascript
client.on("message", (topic, message) => {
  document.querySelector("button").style.transform = "rotate(" + message + "deg)";
});
```
```javascript
<div>My element</div>

client.on("message", (topic, message) => {
  document.querySelector("div").style.transform = "translate(" + message.x + "px, " + message.y + "px)";
});
```

---
layout: cover
level: 2
---

## Change the text of an element

```javascript
client.on("message", (topic, message) => {
  document.querySelector("h1").textContent = message;
});
```

---
layout: cover
level: 2
---

## Listen to different topics

```javascript
client.subscribe("mouse");
client.subscribe("click");
client.subscribe("scroll");

function messageReceived(topic, message) {
  if(topic === "mouse") {
    const {x, y} = JSON.parse(message);
    console.log(x, y);
  } else if (topic === "click") {
    console.log(message);
  } else if (topic === "scroll") {
    console.log(message);
  }
};
```

---
level: 2
layout: two-cols
---


<template v-slot:default>

## Arduino Publish

```cpp
void loop() {
  int analogValue = analogRead(A0);
  client.publish("analog", String(analogValue));
}
```
```cpp
void loop() {
  int digitalValue = digitalRead(2);
  client.publish("digital", String(digitalValue));
}
```

</template>
<template v-slot:right>

## Arduino Subscribe

```cpp
void messageReceived(String &topic, String &message) {
    int analogValue = message.toInt();
    analogWrite(9, analogValue);
}
```
```cpp
void messageReceived(String &topic, String &message) {
    int digitalValue = message.toInt();
    digitalWrite(13, digitalValue);
}
```
</template>

<style>
.slidev-layout {
  gap: 0.5rem;
}
</style>
