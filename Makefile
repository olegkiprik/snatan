all: snatan
snatan:
	g++ -std=c++17 -W -O3 -march=native -o snatan GraphicalUtility.cpp BlockSnake.cpp ParticleSystem.cpp CentralViewScreen.cpp PausableClock.cpp LanguageLoader.cpp ChallengeVisual.cpp RandomizerImpl.cpp Levels.cpp Digits.cpp LevelStatistics.cpp sha256.cpp Endianness.cpp SnakeDrawable.cpp Main.cpp SnakeWorld.cpp MemoryOutputStream.cpp SoundPlayer.cpp FileOutputStream.cpp SoundThrower.cpp ObjectBehaviour.cpp SpriteArray.cpp Game.cpp ObjectBehaviourLoader.cpp GameDrawable.cpp TextureLoader.cpp GameImpl.cpp ObjParamEnumUtility.cpp -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
.PHONY:
	clean all
clean:
	rm snatan
