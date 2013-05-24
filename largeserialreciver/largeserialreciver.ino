const int BUFSIZE = 230;         // max message size is BUFSIZE - 1 to leave room for the end-of-string NULL character (i.e. 0x00)
const char EOM = '*';            // marks the end of the message

char buffer[BUFSIZE];    // here we store the message as we receive it char by char
int  bufPos = 0;                // where to store the next received char in buffer


// this function will have to analyze the message's contents and
// take appropriate action
void processMessage(const char *msg) {
    // this is only a test, so we just
    // print out the message
    Serial.print("Received: ");
    Serial.println(msg);
}


void setup()
{
    Serial.begin(9600);
}


void loop ()
{
    char ch;
    
    while (Serial.available() > 0) {
        ch = Serial.read();
        
        if (ch == EOM) {            // end-of-message
            buffer[bufPos] = 0;     // string terminator
            processMessage(buffer);  // do something with the received message
            bufPos = 0;             // restart for next messages
        }
        else {
            if (bufPos < (BUFSIZE - 1)) {        // if there's still room in the buffer
                buffer[bufPos] = ch;             // store the received char
                bufPos++;                        // forward 1 position in buffer
            }
            else {
                Serial.println("Lost byte!");    // no more room, have to throw away the received char
            }
        }
    }
}

