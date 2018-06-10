#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor colors[] = {ofColor(139, 39, 39), ofColor(39, 39, 139)};

	for (int x = 0; x < 3; x++) {

		for (int y = 0; y < 3; y++) {

			ofPushMatrix();
			ofTranslate(x * 240 + 120, y * 240 + 120);

			for (int radius = 20; radius < 120; radius += 10) {

				for (int i = 0; i < 2; i++) {

					int deg_start = radius + ofGetFrameNum() + (x + y) * 120 + i * 180;
					for (int deg = deg_start; deg < deg_start + 120; deg += 5) {

						ofPoint p1(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
						ofPoint p2(radius * cos((deg + 5) * DEG_TO_RAD), radius * sin((deg + 5) * DEG_TO_RAD));

						ofSetColor(colors[i], ofMap(deg, deg_start, deg_start + 120, 0, 255));
						ofDrawLine(p1, p2);
					}

					ofDrawCircle(radius * cos((deg_start + 120) * DEG_TO_RAD), radius * sin((deg_start + 120) * DEG_TO_RAD), 3);
				}
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}