#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void setPixel(int horizontal,int vertical,unsigned char R,
            unsigned char G,unsigned char B,int w, unsigned char pixels[]);
        void getPixel(int horizontal,int vertical,unsigned char* R,
            unsigned char* G,unsigned char* B,int w, unsigned char pixels[]);
        ofVideoGrabber vidGrabber;
        int camWidth;
        int camHeight;

        ofVideoPlayer player;
        ofTexture texture;
        unsigned char * texpixels, * vidpixels;

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};
