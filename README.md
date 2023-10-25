# junbot_app

[Qt for Android](https://www.youtube.com/watch?v=w2RRgRGHsDA)

# Installation

1. QMQTT
```
git clone git://code.qt.io/qt/qtmqtt.git
git checkout <version of Qt> # version of Qt: v5.12.5
sudo apt-get install qtbase5-private-dev
qmake => make => make install
```

2. Run


# TODO:

- [x] Clean code and build 
- [x] Add feature table and permission
- [ ] Login Screen and Login feature, get data, compress to Json format and send to junbot_gui => check login status and return
- [x] Connect via MQTT Broker and visual Robot Status in Home Screen
- [x] Send control message to Robot by Json format (Update this feature in junbot_gui)
- [ ] Get DeliveryTarget from junbot_gui via MQTT Broker and visual in Control Screen
- [ ] Send DeliveryTarget to Robot by Json format (Update this feature in junbot_gui)
- [ ] Notify robot status
- [ ] Test and fix bug

