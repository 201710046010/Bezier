#include "ofApp.h"
#include <list>
#include <vector>
#include <iterator>
using namespace std;

ofPlanePrimitive plane;
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);

	buton.addListener(this, &ofApp::buttonPressed);
	slider.addListener(this, &ofApp::sliderChanged);
	gui.setup();
	t = 1 / T;
	gui.add(slider.setup("select X", 5, 2, ofGetWidth()));
	gui.add(buton.setup("boton pintar"));
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

float interpolate(float n1, float n2, float t)
{
	return n1 + ((n2 - n1) * t);
}

void ofApp::buttonPressed() {
	numPuntos = 0;
	numQ = 0;
	line.clear();
	limpialinea = false;
	cout << "ingresar saltos \n";
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
	ofPoint pt;
	pt.set(x, y);
	puntos[numPuntos] = pt;
	line.addVertex(pt);
	numPuntos++;
	if (numPuntos > 2) {
		// puntos intermedios 
		ofPoint Pintermedios[100];
		for (int i = 0; i < numPuntos; i++) {
			if (i + 1 < numPuntos) {
				ofPoint punto = puntos[i];
				ofPoint punto1 = puntos[i + 1];
				

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