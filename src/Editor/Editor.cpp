#include "LevelEditor/Editor.h"

LevelEditor* LevelEditor::m_instance = NULL;

LevelEditor::LevelEditor() {};

LevelEditor::~LevelEditor() {};

LevelEditor* LevelEditor::instance() {
	if (m_instance == NULL) {
		m_instance = new LevelEditor();
	}

	return m_instance;
}


#pragma region I_SCENE
//returns true if the event has been processed and no further handling is needed
bool LevelEditor::handleEvent(sf::Event &Event) {
	throw E_NOTIMPL;
	//return false;
}

void LevelEditor::update(sf::Time const &elapsedTime) {
	throw E_NOTIMPL;
}

void LevelEditor::draw(sf::RenderWindow &w) {
	throw E_NOTIMPL;
}
#pragma endregion

#pragma region GET/SET
#pragma endregion

