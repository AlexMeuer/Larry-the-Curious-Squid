#ifndef _HEADSUPDISPLAY_
#define _HEADSUPDISPLAY_

class HeadsUpDisplay {
private:
	static HeadsUpDisplay *m_instance;
	HeadsUpDisplay() {}
public:
	~HeadsUpDisplay() {}

	static HeadsUpDisplay* instance() { return instance == NULL ? m_instance = new HeadsUpDisplay() : m_instance; }

};
#endif