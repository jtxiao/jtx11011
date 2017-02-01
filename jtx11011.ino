//PUT YOUR VARIABLES HERE

void setup(){

    Spark.function("my-main", myMain);

    //PUT YOUR SETUP CODE HERE. Note: Only three more functions allowed!
    // test everything using the return int from a function!


    //RGB.control(true);
    //RGB.color(0, 255, 255);  //cyan
    RGB.brightness(255);    // 1=very low light, 255 = max


}

void loop(){

    //PUT YOUR LOOP CODE HERE

}

int myMain(String myCode) {

    myCode.toUpperCase();           // set argument to uppercase--remove for better security

    // used send instead of write since I needed it to be 4 characters long.


    // d7-send-1 or d7-send-high or d7-send-on    to turn on D7
    // d7-send-0   or d7-send-low  or d7-send-off to tuurn off D7
    // d5-read    read D5

    // a0-send-0     turn A0 off
    // a0-send-255   turn A0 maximum
    // a1-read       read A1

    // Block sets pinNumber for digital 0-7 or analog 10-17 from the number
    int mySetWrite = 0;
    int pinNumber = myCode.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1;
    if (myCode.startsWith("A")){pinNumber = pinNumber+10;}  //+10 is for analog numbers

    // myCode parsing complete


    if (pinNumber < 9) {   // digital pins activated

        if (pinNumber == 5) {
            pinMode(5, OUTPUT);
            pinMode(4, OUTPUT);
            digitalWrite(5, 1);
            delay(1);
            digitalWrite(5,0);
            delay(11);
            digitalWrite(5, 1);
            delay(1);
            digitalWrite(5,0);
            delay(11);
            digitalWrite(5, 1);
            delay(1);
            digitalWrite(5,0);
            delay(11);
            digitalWrite(4,1);
            delay(1);
            digitalWrite(4,0);
        }

        else {
            pinMode(pinNumber, OUTPUT);
            digitalWrite(pinNumber, 1);
            delay(1)
            digitalWrite(pinNumber, 0);
        }


    }  else {      // analog pins activate

        pinMode(pinNumber, OUTPUT);
        analogWrite(pinNumber,  1);
        delay(1)
        digitalWrite(pinNumber,0);

      }

}
