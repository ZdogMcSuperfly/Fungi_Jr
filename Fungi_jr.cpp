// See: https://mlxxxp.github.io/documents/Arduino/libraries/Arduboy2/Doxygen/html/
#include <Arduboy2.h>
 
Arduboy2 arduboy;

// init graphics
const uint8_t PROGMEM wall[] = {
8, 8,
0xff, 0xff, 0xef, 0xef, 0xbf, 0xbf, 0xff, 0xff, 
};

const uint8_t PROGMEM ground[] = {
8, 8,
0xfb, 0xfb, 0xeb, 0xeb, 0xbb, 0xbb, 0xfb, 0xfb, 
};

const uint8_t PROGMEM platform[] = {
8, 8,
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
};

const uint8_t PROGMEM ladder[] = {
8, 8,
0x00, 0xff, 0x00, 0x54, 0x54, 0x00, 0xff, 0x00, 
};

const uint8_t PROGMEM laddertop[] = {
8, 8,
0x01, 0xff, 0x01, 0x55, 0x55, 0x01, 0xff, 0x01, 
};

const uint8_t PROGMEM spout[] = {
8, 8,
0x00, 0x80, 0xf8, 0xfc, 0xfc, 0xfc, 0xbc, 0x3c, 
};

const uint8_t PROGMEM pipe[] = {
8, 8,
0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 
};

const uint8_t PROGMEM pipetop[] = {
8, 8,
0x3c, 0x3c, 0x42, 0x5a, 0x5a, 0x42, 0x3c, 0x00, 
};

const uint8_t PROGMEM water[] = {
8, 8,
0x00, 0x70, 0x99, 0x9f, 0x9f, 0x99, 0x70, 0x00, 
};

const uint8_t PROGMEM empty[] = {
8, 8,
0x3f, 0x41, 0x81, 0x81, 0x81, 0x81, 0x41, 0x3f, 
};

const uint8_t PROGMEM full[] = {
8, 8,
0x3f, 0x41, 0xbd, 0xbd, 0xbd, 0xbd, 0x41, 0x3f, 
};

const uint8_t PROGMEM player[] = {
0x00, 0x00, 0xb0, 0x78, 0x78, 0xb0, 0x00, 0x00, 
};

const uint8_t PROGMEM fragile[] = {
8, 8,
0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 
};

const uint8_t PROGMEM bad[] = {
0x00, 0x00, 0xb0, 0x48, 0x48, 0xb0, 0x00, 0x00, 
};

const uint8_t PROGMEM bop[] = {
0x00, 0x00, 0x68, 0x90, 0x90, 0x68, 0x00, 0x00, 
};

const uint8_t PROGMEM bullet[] = {
0x00, 0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x00, 
};

const uint8_t PROGMEM bulletmask[] = {
0x18, 0x24, 0x42, 0x81, 0x66, 0x24, 0x24, 0x18, 
};

const uint8_t PROGMEM spouthor[] = {
8, 8,
0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7e, 
};

const uint8_t PROGMEM gameover[] = {
0x00, 0x38, 0x7c, 0xc6, 0x82, 0x92, 0xf2, 0xf2, 0x00, 0xf8, 0xfc, 0x26, 0x22, 0x26, 0xfc, 0xf8, 0x00, 0xfe, 0xfe, 0x1c, 0x38, 0x1c, 0xfe, 0xfe, 0x00, 0x00, 0xfe, 0xfe, 0x92, 0x92, 0x92, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xfe, 0x82, 0x82, 0x82, 0xfe, 0x7c, 0x00, 0x1e, 0x3e, 0x70, 0xe0, 0x70, 0x3e, 0x1e, 0x00, 0x00, 0xfe, 0xfe, 0x92, 0x92, 0x92, 0x82, 0x00, 0xfe, 0xfe, 0x22, 0x62, 0xf2, 0xde, 0x9c, 0x00, 0x00, 0x00, 0xbe, 0xbe, 0x0e, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM gameovermask[] = {
0x38, 0x44, 0x82, 0x39, 0x7d, 0x6d, 0x0d, 0x0d, 0xfe, 0x04, 0x02, 0xd9, 0xdd, 0xd9, 0x02, 0x04, 0xfe, 0x01, 0x01, 0xe2, 0xc4, 0xe2, 0x01, 0x01, 0xfe, 0xfe, 0x01, 0x01, 0x6d, 0x6d, 0x6d, 0x55, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x7d, 0x7d, 0x7d, 0x01, 0x82, 0x7e, 0x21, 0x41, 0x8e, 0x10, 0x8e, 0x41, 0x21, 0x1e, 0xfe, 0x01, 0x01, 0x6d, 0x6d, 0x6d, 0x7d, 0xfe, 0x01, 0x01, 0xdd, 0x9d, 0x0d, 0x21, 0x62, 0x9c, 0x00, 0xbe, 0x41, 0x41, 0xb1, 0x0e, 
0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 
};

const uint8_t PROGMEM titlescreen[] = {
54, 64,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x04, 0x62, 0x32, 0x10, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x60, 0x30, 0x10, 0xb8, 0xfc, 0x7c, 0x38, 0x10, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x30, 0x10, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x48, 0x48, 0x4c, 0x84, 0x84, 0x04, 0x06, 0x06, 0x00, 0x00, 0xe0, 0xb0, 0x4c, 0xe6, 0xf2, 0x32, 0xc3, 0x61, 0xb1, 0x11, 0x13, 0x1e, 0x0f, 0x19, 0xf8, 0x08, 0x0c, 0x06, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x03, 0x80, 0xe0, 0x30, 0x0c, 0x02, 0xc1, 0x61, 0x20, 0x20, 0x60, 0xc0, 0x80, 0x00, 0x00, 0xf9, 0x87, 0x02, 0x06, 0xe4, 0x0c, 0x38, 0xf3, 0x3c, 0x3b, 0x25, 0x5a, 0xdd, 0xde, 0x5f, 0x5f, 0x2e, 0x36, 0x10, 0x0e, 0x03, 0x00, 0x18, 0x0e, 0x43, 0x60, 0x30, 0x18, 0x0e, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x70, 0x1e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x38, 0x60, 0xc6, 0x80, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0x03, 0x06, 0x08, 0x08, 0x08, 0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x30, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x30, 0x18, 0x08, 0x08, 0x18, 0x70, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x30, 0x10, 0x1c, 0x07, 0x80, 0x80, 0x60, 0x3c, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x08, 0x18, 0x10, 0x10, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xe0, 0x30, 0x10, 0x08, 0x08, 0x09, 0x08, 0x0c, 0x04, 0x04, 0x04, 0xc4, 0x74, 0x1c, 0x0c, 0x06, 0x07, 0x03, 0x02, 0x02, 0x86, 0x84, 0x88, 0x98, 0xf0, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x30, 0x08, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x06, 0x02, 0x03, 0x0c, 0x18, 0x30, 0x20, 0xa0, 0xe0, 0x60, 0x20, 0x30, 0xf8, 0x1f, 0x0c, 0x04, 0x06, 0x02, 0x02, 0x03, 0x01, 0x81, 0xc1, 0x60, 0x30, 0x18, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x18, 0x30, 0x20, 0x20, 0x30, 0x10, 0x10, 0x18, 0x08, 0x08, 0x0c, 0x04, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const uint8_t PROGMEM titlescreentext[] = {
64, 8,
0x60, 0x1d, 0x0b, 0x09, 0x1b, 0x03, 0x00, 0x00, 0x3d, 0x43, 0x40, 0x61, 0x3f, 0x1f, 0x00, 0x00, 0x71, 0x0f, 0x06, 0x38, 0x70, 0x1f, 0x00, 0x00, 0x3c, 0x42, 0x41, 0x49, 0x49, 0x3a, 0x00, 0x00, 0x00, 0x40, 0x7d, 0x7f, 0x43, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x60, 0x40, 0x7d, 0x3f, 0x03, 0x01, 0x00, 0x00, 0x60, 0x1d, 0x0b, 0x39, 0x6f, 0x46, 0x00, 0x00, 0x20, 
};

const uint8_t PROGMEM zsoft[] = {
33, 4,
0x09, 0x0d, 0x0b, 0x09, 0x00, 0x04, 0x04, 0x00, 0x0a, 0x0b, 0x0b, 0x05, 0x00, 0x06, 0x09, 0x09, 0x06, 0x00, 0x0f, 0x05, 0x05, 0x01, 0x00, 0x01, 0x0f, 0x01, 0x00, 0x0b, 0x00, 0x05, 0x08, 0x08, 0x05, 
};

//init playfield: 0=wall,1=ground,2=platform,3=ladder,4=laddertop,5=spout,6=pipe,7=pipetop,8=null
int playfield[] = {
0,0,0,0,5,6,6,6,6,6,7,7,0,0,
0,8,4,8,8,8,8,8,8,8,8,8,0,0,
0,8,3,8,8,8,8,8,8,8,8,8,0,0,
0,1,3,2,4,2,8,8,8,4,1,1,0,0,
0,0,8,8,8,8,8,8,8,3,0,0,0,0,
0,0,2,2,2,4,4,2,2,3,0,0,0,0,
0,0,8,8,8,8,8,8,8,8,0,0,0,0,
0,0,1,1,1,1,1,1,1,1,0,0,0,0,
};

//init values
int score = 0;
int water_tank_level = 0;
int player_lives = 3;
int x = 0; int y = 0; //used for loops that need to change x,y values
bool water_collected = false;
long frame_counter = 0;
bool water_tank_animation = false; //filling the tank
bool water_tank_animation_2 = false; //emptying the tank

int screen_mode = 0; //0=titlescreen,1=game
int titlescreen_x = 0;
int titlescreen_y = 0;
char titlescreen_direction = 'E';

int gameover_y = -14;
float blackground_size = 13;
float blackground_y = -14;

int badguy_x = 32; //bad guy is not fixed to a grid like the player is
int badguy_y = 0;
char badguy_direction = 'S';

int bopguy_x = 8;
int bopguy_y = 32;
char bopguy_direction = 'E';

int bullet_x = 112;
int bullet_y = random(2,6);

int player_x = 2; int player_y = 6;
int player_state = 0; //0=walking,1=jumping,2=climbing,3=big jump,4=win,5=gameover
long player_start_timer = 0; //arduboy.everyXFrames() huh didnt know this excisted

int players_left = 0;
int players_center = 0;
int players_up = 0;
int players_down = 0;
int players_right = 0;
int players_downleft = 0;
int players_downright = 0;

int level = 0; //0=no dudes,1=walker,2=bullet,3=bopper

void setup() {arduboy.begin();arduboy.setFrameRate(30);}

void reset() {
  // code to be executed
  player_x = 2; 
  player_y = 6; 
  water_collected = false; 
  player_state = 0; 
  water_tank_animation = false;
  water_tank_animation_2 = false;
  arduboy.setRGBled(0,0,0); 
  badguy_direction = 'S'; 
  badguy_x = 32; 
  badguy_y = 0; 
  bopguy_x = 8;
  bopguy_y = 32;
  bopguy_direction = 'E';
  bullet_x = 112; 
  bullet_y = random(2,6);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  arduboy.clear();
  arduboy.pollButtons();

  //game goes here
  if (screen_mode == 1) {
  //check whats around the player
  players_left = playfield[(player_y*14)+(player_x-1)]; //(x*width)+y finds 1D array index from 2 values 
  players_center = playfield[(player_y*14)+(player_x)];
  players_up = playfield[((player_y-1)*14)+(player_x)];
  players_down = playfield[((player_y+1)*14)+(player_x)];
  players_right = playfield[(player_y*14)+(player_x+1)];
  players_downleft = playfield[((player_y+1)*14)+(player_x-1)];
  players_downright = playfield[((player_y+1)*14)+(player_x+1)];
  //score = player_state; //debug
  
  //define collision rects
  Rect player_col = { (player_x*8)+2, (player_y*8)+3, 4, 5 };
  Rect badguy_col = { badguy_x+2, badguy_y, 4, 8 };
  Rect bullet_col = { bullet_x+1, (bullet_y*8)+1, 7, 7 };
  Rect bopguy_col = { bopguy_x+2, bopguy_y, 4, 8 };

  //check collision with enemys
  if (arduboy.collide(player_col, badguy_col) == true) { reset(); player_lives -= 1; }
  if (arduboy.collide(player_col, bullet_col) == true) { reset(); player_lives -= 1; }
  if (arduboy.collide(player_col, bopguy_col) == true) { reset(); player_lives -= 1; }
  if (player_lives == 0) {player_state = 6; badguy_direction = 'N'; bullet_x = -27; }
  
  if (player_state == 6) { if (arduboy.everyXFrames(70)) { player_state = 5; player_lives = -1; } }
  
  //water bottle pickup collision detection
  if ((player_x == 1) && (player_y == 2)) { water_collected = true; }
  
  //end of level detection 
  if ((player_x == 9) && (player_y == 2) && (player_state == 0)) { player_state = 4; water_tank_level += 1; score += 1; level += 1; badguy_direction = 'N'; bullet_x = -16;}
  
  //input and collision detection
  //walking state
  if (player_state == 0) {
    if ((arduboy.justPressed(B_BUTTON)) && (players_downright == 8) && (water_collected == true)) {player_x += 1; player_y -= 1; player_state = 3; player_start_timer = frame_counter; } //do a big jump and clear the gap to the fragile platform
    else if ((arduboy.justPressed(RIGHT_BUTTON)) && (players_downright == 8)) { player_x = player_x; }  //move right and check for ground to stand on
    else if ((arduboy.justPressed(LEFT_BUTTON)) && (players_downleft == 8)) { player_x = player_x; }  //move right and check for ground to stand on
    else if ((arduboy.justPressed(RIGHT_BUTTON)) && (players_right != 0)) { player_x += 1; }  //move right and check for wall
    else if ((arduboy.justPressed(LEFT_BUTTON)) && (players_left != 0)) { player_x -= 1; } //move left and check for wall
    else if ((arduboy.justPressed(A_BUTTON)) && (players_up == 2)) { player_y -= 1; player_state = 1; player_start_timer = frame_counter; } //jumping below a platform
    else if ((arduboy.justPressed(A_BUTTON)) && (players_up == 3)) { player_y -= 1; player_state = 2; } //jumping below a ladder
    else if ((arduboy.justPressed(A_BUTTON)) && (players_up == 4)) { player_y -= 1; player_state = 2; } //jumping below a laddertop
    else if ((arduboy.justPressed(A_BUTTON)) && (players_up == 8)) { player_y -= 1; player_state = 1; player_start_timer = frame_counter; } //jumping below nothing
    if ((arduboy.justPressed(RIGHT_BUTTON)) && (players_right == 3)) { player_state = 2; } //get back onto a ladder you walk over it too the right
    if ((arduboy.justPressed(LEFT_BUTTON)) && (players_left == 3)) { player_state = 2; } //get back onto a ladder you walk over it too the right
  }
  
  //jumping state
  if (player_state == 1) {
    if (frame_counter - player_start_timer == 15) { player_y += 1; player_state = 0; } //pseduo gravity
  }
  
  //big jump state
  if (player_state == 3) {
    if (frame_counter - player_start_timer == 15) { player_x += 1; player_y += 1; player_state = 0; } //pseduo gravity
  }
   
  //climbing state
  if (player_state == 2) {
    if ((arduboy.justPressed(UP_BUTTON)) && (players_center != 4)) { player_y -= 1; } //climb up ladder
    else if ((arduboy.justPressed(DOWN_BUTTON)) && (players_down == 3)) { player_y += 1; } //climb down ladder
    else if ((arduboy.justPressed(DOWN_BUTTON)) && (players_down == 8)) { player_y += 1; player_state = 0; } //fall off ladder and back onto ground
    else if ((arduboy.justPressed(LEFT_BUTTON)) && (players_left == 4)) { player_x -= 1; } //move to an ajaycent ladder on the left
    else if ((arduboy.justPressed(RIGHT_BUTTON)) && (players_right == 4)) { player_x += 1; } //move to an ajaycent ladder on the right
    else if ((arduboy.justPressed(LEFT_BUTTON)) && (players_downleft == 8)) { player_x -= 1; player_state = 1; player_start_timer = frame_counter; } //fall off ladder at height and to the left
    else if ((arduboy.justPressed(RIGHT_BUTTON)) && (players_downright == 8)) { player_x += 1; player_state = 1; player_start_timer = frame_counter; } //fall off ladder at height and to the right
    else if ((arduboy.justPressed(LEFT_BUTTON)) && (players_downleft == 1)) { player_x -= 1; player_state = 0; } //get off ladder to the left and onto ground
    else if ((arduboy.justPressed(LEFT_BUTTON)) && (players_downleft == 2)) { player_x -= 1; player_state = 0; } //get off ladder to the left and onto a platform   
    else if ((arduboy.justPressed(RIGHT_BUTTON)) && (players_downright == 2)) { player_x += 1; player_state = 0; } //get off ladder to the right and onto a platform
  }
  
  //win state
  if (player_state == 4) {
    //reset game
    if ((arduboy.justPressed(A_BUTTON)) && (water_tank_animation_2 != true)) { 
      if (water_tank_level == 4) { water_tank_animation = false; water_tank_animation_2 = true; }
      else { reset(); }
    }
    //play a little flashing animation
    if (water_tank_animation_2 == true) {
      if (arduboy.everyXFrames(30)) {
        water_tank_level -= 1;
        score += 1;
        if (water_tank_level == -1) { reset(); score -= 1; water_tank_level = 0; level = 0; }
      }    
    }
    else {
      if (arduboy.everyXFrames(15)) {
        if (water_tank_animation == false) { arduboy.setRGBled(0,0,0); water_tank_animation = true; }
        else if (water_tank_animation == true) { arduboy.setRGBled(0,255,0); water_tank_animation = false; }
      }
    }    
  }
  
  //disable enemy if not the right level
  if (level == 0) { badguy_x = -28; bullet_x = -28; bopguy_x = -28; }
  if (level == 1) { bullet_x = -28; bopguy_x = -28; }
  if (level == 2) { bopguy_x = -28; }
  
  //move enemy
  if (badguy_direction != 'N') {
    //waypoints for badguy
    if ((badguy_x == 32) && (badguy_y == 16)) { badguy_direction = 'W'; }
    if ((badguy_x == 16) && (badguy_y == 16)) { badguy_direction = 'S'; }
    if ((badguy_x == 16) && (badguy_y == 32)) { badguy_direction = 'E'; }
    if ((badguy_x == 72) && (badguy_y == 32)) { badguy_direction = 'S'; }
    if ((badguy_x == 72) && (badguy_y == 48)) { badguy_direction = 'W'; }
    if ((badguy_x == 16) && (badguy_y == 48)) { badguy_direction = 'S'; }
    if ((badguy_x == 16) && (badguy_y == 64)) { badguy_direction = 'S'; badguy_x = 32; badguy_y = 0; }
    
    //waypoint for bopguy
    if ((bopguy_x == 16) && (bopguy_y == 32)) { bopguy_direction = 'N'; }
    if ((bopguy_x == 24) && (bopguy_y == 24)) { bopguy_direction = 'S'; }
    if ((bopguy_x == 32) && (bopguy_y == 32)) { bopguy_direction = 'N'; }
    if ((bopguy_x == 40) && (bopguy_y == 24)) { bopguy_direction = 'S'; }
    if ((bopguy_x == 48) && (bopguy_y == 32)) { bopguy_direction = 'N'; }
    if ((bopguy_x == 56) && (bopguy_y == 24)) { bopguy_direction = 'S'; }
    if ((bopguy_x == 64) && (bopguy_y == 32)) { bopguy_direction = 'N'; }
    if ((bopguy_x == 72) && (bopguy_y == 24)) { bopguy_direction = 'D'; }
    if ((bopguy_x == 72) && (bopguy_y == 64)) { bopguy_direction = 'E'; bopguy_x = 8; bopguy_y = 32; }
    
    //waypoint for bullet
    if (bullet_x == -8) { bullet_x = 112; bullet_y = random(2,6); }
    
    //movement
    if (arduboy.everyXFrames(1)) {
      if (badguy_direction == 'S') { badguy_y += 1; }
      if (badguy_direction == 'W') { badguy_x -= 1; }
      if (badguy_direction == 'E') { badguy_x += 1; }
      bullet_x -= 1;
    }
    
    if (arduboy.everyXFrames(4)) {
      if (bopguy_direction == 'N') { bopguy_x += 1; bopguy_y -= 1; }
      if (bopguy_direction == 'S') { bopguy_x += 1; bopguy_y += 1; }
      if (bopguy_direction == 'D') { bopguy_y += 1; }
      if (bopguy_direction == 'E') { bopguy_x += 1; }
    }
  }
  
  //draw playfield
  x = 0; y = 0;
  for (int i = 0; i < 14*8; i++) {
    if (playfield[i] == 0) { Sprites::drawOverwrite(x*8, y*8, wall, 0); } //how do you store varibles in arrays this would make this cleaner
    if (playfield[i] == 1) { Sprites::drawOverwrite(x*8, y*8, ground, 0); }
    if (playfield[i] == 2) { Sprites::drawOverwrite(x*8, y*8, platform, 0); }
    if (playfield[i] == 3) { Sprites::drawOverwrite(x*8, y*8, ladder, 0); }
    if (playfield[i] == 4) { Sprites::drawOverwrite(x*8, y*8, laddertop, 0); }
    if (playfield[i] == 5) { Sprites::drawOverwrite(x*8, y*8, spout, 0); }
    if (playfield[i] == 6) { Sprites::drawOverwrite(x*8, y*8, pipe, 0); }
    if (playfield[i] == 7) { Sprites::drawOverwrite(x*8, y*8, pipetop, 0); }
    x++;
    if (x == 14) { x = 0; y++; }
  }
  
  //draw water pickup and fragile platform
  if (water_collected == false) { Sprites::drawOverwrite(8, 16, water, 0); } else { Sprites::drawOverwrite(56, 24, fragile, 0); }
  
  //draw water tank
  //draw it empty
  Sprites::drawOverwrite(80, 8, empty, 0);
  Sprites::drawOverwrite(88, 8, empty, 0);
  Sprites::drawOverwrite(80, 16, empty, 0);
  Sprites::drawOverwrite(88, 16, empty, 0);
  //draw it filling up
  x = 80; y = 16;
  for (int i = 0; i < water_tank_level; i++) {
    Sprites::drawOverwrite(x, y, full, 0);
    x += 8;
    if (i == 1) { x = 80; y = 8; }
  }
  
  //draw lives
  x = 118; y = 0;
  for (int i = 0; i < player_lives; i++) {
    arduboy.drawBitmap(x, y+(i*8), player, 8, 8, 1);
  }
  
  //debug
  //arduboy.setCursor(114,40);
  //arduboy.print(level);
  
  //draw player
  arduboy.drawBitmap(player_x*8, player_y*8, player, 8, 8, WHITE);
  
  //draw bad guy
  arduboy.drawBitmap(badguy_x, badguy_y, bad, 8, 8, WHITE);
  
  //draw bop guy
  arduboy.drawBitmap(bopguy_x, bopguy_y, bop, 8, 8, WHITE);

  //draw pipe
  if ((level == 3) && (water_tank_animation == false)) {
  Sprites::drawOverwrite(0, 32, pipe, 0);
  Sprites::drawOverwrite(8, 32, spouthor, 0);
  }
  
  //draw bullet
  arduboy.drawBitmap(bullet_x, bullet_y*8, bullet, 8, 8, WHITE);
  arduboy.drawBitmap(bullet_x, bullet_y*8, bulletmask, 8, 8, BLACK);
  
  //draw gameover
  if (player_state == 5) {
    if (gameover_y != 27) {
      if (arduboy.everyXFrames(1)) { gameover_y += 1; blackground_y += 1; }
    }
    else {
      if (blackground_y != -8) {
        if (arduboy.everyXFrames(1)) { blackground_size += 1; blackground_y -= 0.5; }
      }
      else if ((blackground_y == -8) && (arduboy.justReleased(A_BUTTON))) {screen_mode = 0;}
    }
  arduboy.fillRect(0,blackground_y,128,blackground_size,BLACK);
  arduboy.fillRect(0,gameover_y+1,128,11,WHITE);
  arduboy.drawBitmap((128/2)-(78/2), gameover_y+2, gameover, 78, 9, WHITE);
  arduboy.drawBitmap((128/2)-(78/2), gameover_y+2, gameovermask, 78, 9, BLACK);
  }
  
  //draw score
  arduboy.setCursor(114,56);
  if (water_tank_animation == false) {
    if (score < 10) { arduboy.print("0"+String(score)); } else { arduboy.print(score); }
  }

  //increment frame counter
  frame_counter++;
  }
  else if (screen_mode == 0) {
    if (arduboy.justReleased(A_BUTTON)) {screen_mode = 1; reset(); player_lives = 3; water_tank_level = 0; level = 0;}
    
    if (titlescreen_x == 1) { titlescreen_direction = 'W'; }
    if (titlescreen_x == -1) { titlescreen_direction = 'E'; }
    if (arduboy.everyXFrames(6)) {
      if (titlescreen_direction == 'E') { titlescreen_x += 1; titlescreen_y += 1; }
      if (titlescreen_direction == 'W') { titlescreen_x -= 1; titlescreen_y -= 1; }
    }
    Sprites::drawOverwrite(titlescreen_x, titlescreen_y, titlescreen, 0);
    Sprites::drawOverwrite(60, 8, titlescreentext, 0);
    Sprites::drawOverwrite(94, 59, zsoft, 0);
  }
  arduboy.display();
}