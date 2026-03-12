# Jobsheet-3-BSI-TVETMARA-Ledang
## 🕌 Doing this repo during ramadan, happy fasting guys
So this jobsheet is the introduction to Internet of Things or IoT for short. there are some stuff to be done on this jobsheet. I'll put them down below
```
1. Make a webserver from the ESP32, showing the details of DHT sensor
2. Setup Blynk on mobile and desktop environment
3. Monitor the data of DHT sensor from Blynk
4. Combine all of em
```
Of course, its not gonna be that easy. But I made it easier for you guys, I hope lol.

### 🛠️ Anyway here are the things needed
1. ESP32 [Product Link](https://my.cytron.io/p-nodemcu-esp32-with-expansion-board)
2. DHT22 [Product Link](https://my.cytron.io/p-dht22-sensor-module-breakout)
3. Breadboard [Product Link](https://my.cytron.io/p-breadboard-mini-170-holes-35mmx42mm)
4. Jumper [Product Link](https://my.cytron.io/p-40-way-20cm-dupont-jumper-wire)

### 💻 Install the Blynk Library
Open your beloved Arduino IDE and go to the library manager, search for the Blynk Library. You know the drill, install it. Picture reference are provided below ᗜˬᗜ


<img width="285" height="282" alt="Blynk Library" src="https://github.com/user-attachments/assets/024d135a-c3e7-417b-82e3-2d58d9774a93" />

yeah I know how to attach pictures on markdown now. Aint that cool

### 🖼️ Physical Setup & Schematic

here is my physical setup, as you can see on the picture below Im using the DHT11 instead of 22. **Its completely okay**, I lost my DHT22, someone borrowed it and idk where it went.

![physical setup](https://github.com/user-attachments/assets/9b286f26-5de1-46c7-a036-896d9a56d4b3)

The schematic setup for this jobsheet is pretty simple too. But eh, for the sake of documentation Im gonna put it here anyway

<img width="443" height="538" alt="schematic js 3 bsi" src="https://github.com/user-attachments/assets/bd49e880-8a77-4ea7-8337-1f0268416fdc" />


### 🌐 Monitoring the DHT via webserver
now were in the first task of this jobsheet. Simply said, we need to connect the esp32 to the internet so that we can show the output of the DHT sensor on a website. The website is built via html in the IDE, nothing fancy for people who learn html. Anyway, the source code is uploaded labelled "DHT_display_WebServer". Do check that out and upload it to your esp. The result are shown below. 

<img width="1854" height="357" alt="IP address for the webserver" src="https://github.com/user-attachments/assets/6ce71335-ee78-4c6c-8806-1e3e86c76fdf" />

this is the expected result when you check the serial monitor running at 115200 baudrate. The IP address might vary!

<img width="1366" height="720" alt="webserver on desktop mode" src="https://github.com/user-attachments/assets/2caca9a9-81ca-4b1f-8780-e51b98caab04" />

here is the result on desktop

![result on mobile device](https://github.com/user-attachments/assets/4c2bbfae-38df-4b91-a964-b1ca37ccd5b0)

the result on mobile device should look like this

> when you want to check the result, make sure your esp and device is connected to the same wifi!

### 🌐 Monitoring the DHT via Blynk
now here is where stuff gets real, I will be providing you guys with a YouTube video on how to configure Blynk. The source code labelled "DHT_display_Blynk" is also provided, do check them out.

[Here's the video. Click me!](https://youtu.be/hQmJOk454Cw)

> How it works ⬇️

Blynk is a gateway of IoT. In this jobsheet, it demonstrates the capability of wireless monitoring. The first task we have to connect to the same wifi connection. This isnt the case for Blynk however, you can check the status of the sensor whenever you are, even though your are not connected to the same connection.

> The workflow ⬇️

Blynk provides us with a template to monitor our projects. Inside the template we have to insert a datastream which is the input of the sensor. One datastream is for one input only. This means for some components that can give more than one output, we have to insert individual datastream. In our case here, DHT sensor can read 2 input, temperature and humidity. Therefore, 2 datastreams are needed. After setting up the datastream, building a dashboard is the next step. Dashboard is important because user interface is needed to understand what is happening without going developer mode.

### 🌐 Code Modifications
For this section, we just have to combine both monitoring method via Webserver and Blynk. You know the drill, check the uploaded file. I label them "DHT_monitoring_mod". Oh yeah youtube video will also be provided, so do check them for reference!

[link here!](https://youtu.be/1MPRxVlzirs)

## We're done! ᗜ⩊ᗜ
to be fair, this repo is a bit longer than before. Because I feel like I need to give a little more detail to get people complete this jobsheet, but I dont want them to feel overwhelmed. Its difficult lol but Im glad I finished it. Till we meet again!


to do before making the repo public
- [x] schematic diagram
- [x] physical setup
- [x] library install
- [x] coding for task 1 (monitoring using webserver)
- [x] check the result on browser
- [x] next task monitor using blynk
- [x] login to blynk, setup some stuff
- [x] coding for task 2
- [x] check result
- [ ] video blynk
- [ ] video webserver and blynk
- [ ] DONE!

