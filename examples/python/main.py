import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, reason_code, properties):
    print(f"Connected with result code {reason_code}")
    client.subscribe("$SYS/#")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)

mqttc.tls_set(tls_version=mqtt.ssl.PROTOCOL_TLSv1_2, cert_reqs=mqtt.ssl.CERT_NONE)

mqttc.tls_insecure_set(True)
mqttc.username_pw_set("username", password="password")

mqttc.on_connect = on_connect
mqttc.on_message = on_message

mqttc.connect("37.97.203.138", 8883, 60)

mqttc.loop_forever()