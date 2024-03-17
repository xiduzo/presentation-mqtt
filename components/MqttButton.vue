<script setup lang="ts">
import { ref } from "vue";
import MQTT from "mqtt";

let client = null;

function click() {
    if (!client) {
        client = MQTT.connect("wss://mdd:loislane@mdd-tardis.net:9001", {
            clientId: "presentation",
        });
        client.on("connect", function () {
            client.subscribe("secret/message");
        });
    }

    client.publish("secret/message", "↑ ↑ ↓ ↓ ← → ← → B A");
}
</script>

<template>
    <button
        border="1 main rounded-md"
        p="x-2"
        font="mono"
        tabindex="0"
        outline="!none"
        hover:bg="gray-400 opacity-20"
        active:scale="!98"
        @click="click"
    >
        <div p="5" m="2" rounded="full" w="2" h="2" bg="#D5EEF4"></div>
    </button>
</template>
