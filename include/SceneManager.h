#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include <unordered_map>
#include "Scene.h"
#include "Level.h"

using namespace std;

//singleton class to handle scenes and the navigation between them
class SceneManager {
private:
	unordered_map<string, I_Scene*> m_scenes;

	string currentScene;

	static SceneManager *m_instance;

	SceneManager() {}

public:
	~SceneManager() {}

	static SceneManager* instance() {
		if ( m_instance == NULL ) {
			m_instance = new SceneManager();
		}

		return m_instance;
	}

	const string getCurrentScene() const {
		return currentScene;
	}

	template<typename T>
	void createScene( string name, T* derivedSceneObject ) {
		/*if ( typeid T* != typeid I_Scene* )
			return false;*/

		m_scenes[name] = derivedSceneObject;
		//m_scenes[name]->name = name;
		//m_scenes[name]->dispose = &SceneManager::deleteScene;

		//return true;
	}
};
#endif