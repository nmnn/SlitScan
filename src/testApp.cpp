#include "testApp.h"

//set variables
int video_width     = 320;
int video_height    = 240;
int video_slice_x   = video_width/2;
int window_width    = 240;
int window_height   = video_height;
int draw_position_x = 0;
bool newFrame       = false;

//--------------------------------------------------------------
void testApp::setup(){
    camWidth = vidGrabber.getWidth();
    camHeight = vidGrabber.getHeight();

    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320, 240);

    video_width = vidGrabber.getWidth();
    video_height = vidGrabber.getHeight();

    texture.allocate(window_width, window_height, GL_RGB);
    texpixels = new unsigned char [window_width * window_height * 3];
}

//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.update();
    newFrame = vidGrabber.isInitialized();
    if(newFrame){
    vidpixels = vidGrabber.getPixels();
    for (int y=0; y<window_height; y++){
      unsigned char r, g, b;
      getPixel(video_slice_x, y, &r, &g, &b, video_width, vidpixels);
      setPixel(draw_position_x, y, r, g, b, window_width, texpixels);
    }
    texture.loadData(texpixels, window_width, window_height, GL_RGB);

    draw_position_x++;
    if (draw_position_x >= window_width) {
      draw_position_x = 0;
    }
    newFrame = false;
  }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    texture.draw(0, 0);

    ofDrawBitmapString( ofToString( ofGetFrameRate() ), 400, 10 );
}

//---------------------------------------------------------------
void testApp::setPixel(int horizontal,int vertical,unsigned char R,unsigned char G,
    unsigned char B,int w, unsigned char pixels[]){
    int thisPixel;
    thisPixel = 3*(w * vertical +horizontal);
    pixels[thisPixel]=R;
    pixels[thisPixel+1]=G;
    pixels[thisPixel+2]=B;
}

//--------------------------------------------------------------
void testApp::getPixel(int horizontal,int vertical,unsigned char* R,unsigned char* G,
    unsigned char* B,int w, unsigned char pixels[]){
    int thisPixel;
    thisPixel = 3*(w * vertical +horizontal);
    *R= pixels[thisPixel];
    *G= pixels[thisPixel+1];
    *B= pixels[thisPixel+2];
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
