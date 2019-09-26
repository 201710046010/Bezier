#include "ofApp.h"
#include <list>
#include <vector>
#include <iterator>
using namespace std;

ofPlanePrimitive plane;
//--------------------------------------------------------------
void ofApp::setup() {
	buton.addListener(this, &ofApp::buttonPressed);
	slider.addListener(this, &ofApp::sliderChanged);

	ofSetVerticalSync(true);
	gui.setup();
	
	gui.add(slider.setup("seleccion X", 5, 2, ofGetWidth()));
	gui.add(buton.setup("Pintar"));
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetBackgroundColor(255, 255, 255);
	gui.draw();
	ofSetColor(0, 0, 0, 255);
	line.draw();
}

void ofApp::exit() {
	buton.removeListener(this, &ofApp::buttonPressed);
}

void ofApp::buttonPressed() {
	numPuntos = 0;
	line.clear();
	limpialinea = false;
	cout << "T \n";
	cin >> T;
	t = 1 / T;
	

}
void ofApp::sliderChanged(int &slider) {
	
	x = slider;


}

void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	ofPoint punto;
	punto.set(x, y);
	puntos[numPuntos] = punto;
	line.addVertex(punto);
	numPuntos++;
	if (numPuntos > 2 and T > 0) {
		ofPoint Pintermedios[100];
		for (int i = 0; i < numPuntos; i++) {
			if (i + 1 < numPuntos) {
				float y = 1;
				double t = 1.0/T;
				double origt=t;
				cout << T << "\n";
				cout << t << "\n";
				cout << origt << "\n";
				

				while (y > 0){
					ofPoint punto0 = (1 - t)*puntos[i] + t * puntos[i + 1];
					ofPoint punto1 = (1 - t)*puntos[i + 1] + t * puntos[i + 2];
					line.addVertex(punto0);
					line.addVertex(punto1);
					t = t + origt;
					y = 1 - t;
				}
			}

		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}