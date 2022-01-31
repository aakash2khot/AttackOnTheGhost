#include "../include/SDL2SoundEffects.hpp"
#include <SDL.h>
#include <iostream>

SDL2SoundEffects::SDL2SoundEffects()
{
    // init sound
    SDL_Init(SDL_INIT_AUDIO);

    int rate = 22050;
    Uint16 format = AUDIO_S16SYS;
    int channels = 2;
    int buffers = 4096;

    if (Mix_OpenAudio(rate, format, channels, buffers) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", Mix_GetError());
        exit(-1);
    }
}

SDL2SoundEffects::~SDL2SoundEffects()
{
    SDL_Quit();
}

void SDL2SoundEffects::addSoundEffect(const char *add)
{
    Mix_Chunk *tmpChunk = Mix_LoadWAV(add);

    if (tmpChunk != nullptr)
    {
        mSoundEffectBank.push_back(tmpChunk);
    }
    else
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", Mix_GetError());
    }
}

void SDL2SoundEffects::playSoundEffect(const int play) const
{
    if (play > mSoundEffectBank.size() - 1)
    {
        return;
    }
    if (play >= 0)
        Mix_PlayChannel(-1, mSoundEffectBank[play], 0);
}
