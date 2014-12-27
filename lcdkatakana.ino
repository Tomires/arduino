
    /*        #           #          #     
##########   ####### ########## ########## 
    #    #  #     #      #    #      #     
    #    # # #   #       #    #      #      KATAKANA PARSER r1
   #     #    ###       #     #     #     FOR ARDUINO LCD SHIELD      
  #   # #    ##        #   # #     #            by tomires   
 #     #   ##         #     #     #     


       /\          REQUIRES ARDUINO LCD SHIELD          /\ 
      / !\    OR HD44780U COMPATIBLE LCD CONTROLLER    / !\   
      """"                                             """" 

INSTRUCTIONS FOR USE

  This parser utilizes Hepburn transcription. Please make clear
  distinction between DZI and JI characters. In addition to
  katakana characters, you can use japanese-style dots and braces
  with the parser. Any other characters are not accepted and will
  display a square in the respective position.
  
  Please write in CAPITAL LETTERS!
  
MODIFIERS

  */ boolean SPACESKIP = true; /* Self explanatory.
  
EXAMPLE OF USE
  
  jprint("WATASHI HA ARUDUINO DESU");
  jprint("[INBE-DA-]");
  
  Feel free to use defines as individual characters.

MISSING FEATURES

  There is currently no support for sokuon and combo katakana 
  characters. You can add choonpu by writing a dash.

IDEAS?

  Drop me an e-mail -> me(at)tomires.eu
  
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* CHARACTER DEFINITIONS */

#define A         (char)B10110001
#define I         (char)B10110010
#define U         (char)B10110011
#define E         (char)B10110100
#define O         (char)B10110101

#define KA        (char)B10110110
#define KI        (char)B10110111
#define KU        (char)B10111000
#define KE        (char)B10111001
#define KO        (char)B10111010

#define SA        (char)B10111011
#define SHI       (char)B10111100
#define SU        (char)B10111101
#define SE        (char)B10111110
#define SO        (char)B10111111

#define TA        (char)B11000000
#define CHI       (char)B11000001
#define TSU       (char)B11000010
#define TE        (char)B11000011
#define TO        (char)B11000100

#define NA        (char)B11000101
#define NI        (char)B11000110
#define NU        (char)B11000111
#define NE        (char)B11001000
#define NO        (char)B11001001

#define HA        (char)B11001010
#define HI        (char)B11001011
#define FU        (char)B11001100
#define HE        (char)B11001101
#define HO        (char)B11001110

#define MA        (char)B11001111
#define MI        (char)B11010000
#define MU        (char)B11010001
#define ME        (char)B11010010
#define MO        (char)B11010011

#define YA        (char)B11010100
#define YU        (char)B11010101
#define YO        (char)B11010110

#define RA        (char)B11010111
#define RI        (char)B11011000
#define RU        (char)B11011001
#define RE        (char)B11011010
#define RO        (char)B11011011

#define WA        (char)B11011100
#define WO        (char)B10100110

#define N         (char)B11011101
#define _         (char)B11011110
#define __        (char)B11011111


void jprint(const char * input) {
  int i = 0;
  while(input[i] != '\0') { // fix N
    switch(input[i]) {
      
    case 'A': lcd.print(A); break;
    case 'E': lcd.print(E); break;
    case 'I': lcd.print(I); break;
    case 'O': lcd.print(O); break;
    case 'U': lcd.print(U); break;
    
    case 'K':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(KA); break;
        case 'E': lcd.print(KE); break;
        case 'I': lcd.print(KI); break;
        case 'O': lcd.print(KO); break;
        case 'U': lcd.print(KU); break;
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'G':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(KA); break;
        case 'E': lcd.print(KE); break;
        case 'I': lcd.print(KI); break;
        case 'O': lcd.print(KO); break;
        case 'U': lcd.print(KU); break;
        default: lcd.print((char)255); // error
      }
      lcd.print(_); break;
    
    case 'S':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(SA); break;
        case 'E': lcd.print(SE); break;
        case 'H': i++;
                  if(input[i] == 'I') lcd.print(SHI);
                  else lcd.print((char)255); // error
                  break; 
        case 'O': lcd.print(SO); break;
        case 'U': lcd.print(SU); break;
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'Z':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(SA); break;
        case 'E': lcd.print(SE); break;
        case 'O': lcd.print(SO); break;
        case 'U': lcd.print(SU); break;
        default: lcd.print((char)255); // error
      }
      lcd.print(_); break;
      
    case 'J':
      i++;
      switch(input[i]) {
        case 'I': lcd.print(SHI); break;
        default: lcd.print((char)255); // error
      }
      lcd.print(_); break;
      
    case 'T':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(TA); break;
        case 'E': lcd.print(TE); break;
        case 'O': lcd.print(TO); break;
        case 'S': i++;
                  if(input[i] == 'U') lcd.print(TSU);
                  else lcd.print((char)255); // error
                  break; 
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'D':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(TA); break;
        case 'E': lcd.print(TE); break;
        case 'O': lcd.print(TO); break;
        case 'Z': i++;
                  if(input[i] == 'I') lcd.print(CHI);
                  if(input[i] == 'U') lcd.print(TSU);
                  else lcd.print((char)255); // error
                  break; 
        case 'U': lcd.print(TSU); break;
        default: lcd.print((char)255); // error
      }
      lcd.print(_); break;

    case 'N':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(NA); break;
        case 'E': lcd.print(NE); break;
        case 'I': lcd.print(NI); break; 
        case 'O': lcd.print(NO); break;
        case 'U': lcd.print(NU); break;
        default: lcd.print(N); i--; break; // lone N is acceptable
      }
      break;

    case 'H':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(HA); break;
        case 'E': lcd.print(HE); break;
        case 'I': lcd.print(HI); break; 
        case 'O': lcd.print(HO); break;
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'B':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(HA); break;
        case 'E': lcd.print(HE); break;
        case 'I': lcd.print(HI); break;
        case 'O': lcd.print(HO); break;
        case 'U': lcd.print(FU); break;
        default: lcd.print((char)255); // error
      }
      lcd.print(_); break;
      
    case 'P':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(HA); break;
        case 'E': lcd.print(HE); break;
        case 'I': lcd.print(HI); break;
        case 'O': lcd.print(HO); break;
        case 'U': lcd.print(FU); break;
        default: lcd.print((char)255); // error
      }
      lcd.print(__); break;
      
    case 'M':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(MA); break;
        case 'E': lcd.print(ME); break;
        case 'I': lcd.print(MI); break; 
        case 'O': lcd.print(MO); break;
        case 'U': lcd.print(MU); break;
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'Y':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(YA); break;
        case 'O': lcd.print(YO); break;
        case 'U': lcd.print(YU); break;
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'R':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(RA); break;
        case 'E': lcd.print(RE); break;
        case 'I': lcd.print(RI); break; 
        case 'O': lcd.print(RO); break;
        case 'U': lcd.print(RU); break;
        default: lcd.print((char)255); // error
      }
      break;
      
    case 'W':
      i++;
      switch(input[i]) {
        case 'A': lcd.print(WA); break;
        case 'O': lcd.print(WO); break;
        default: lcd.print((char)255); // error
      }
      break; 
 
    case 'F':
      i++;
      switch(input[i]) {
        case 'U': lcd.print(FU); break;
        default: lcd.print((char)255); // error
      }
      break;  
 
    case 'C':
      i++;
      switch(input[i]) {
        case 'H': i++;
                  if(input[i] == 'I') lcd.print(CHI);
                  else lcd.print((char)255); // error
                  break; 
        default: lcd.print((char)255); // error
      }
      break; 
      
    case '-': lcd.print((char)B10110000); break;
    case '[': lcd.print((char)B10100010); break;
    case ')': lcd.print((char)B10100011); break;
    case ']': lcd.print((char)B10100011); break;
    case '.': lcd.print((char)B10100001); break;
    case ' ': if(SPACESKIP) break;
              else lcd.print((char)254); break;
    default: lcd.print((char)255);
    }
    i++;
  }
}

void setup() {
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 jprint("WATASHI HA [ARUDUINO] DESU.");
 lcd.setCursor(0,1);
 jprint("O GENKI DESU KA.");
}

void loop() {
  
}
