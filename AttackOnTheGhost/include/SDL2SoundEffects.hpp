#pragma once
#include <SDL_mixer.h>
#include <vector>
class SDL2SoundEffects
{
public:
  SDL2SoundEffects();
  ~SDL2SoundEffects();

  void addSoundEffect(const char* add);

  void playSoundEffect(const int play) const;

private:
  
  std::vector<Mix_Chunk*> mSoundEffectBank;

};
