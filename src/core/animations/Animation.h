#ifndef CORE_ANIMATIONS_ANIMATION_H
#define CORE_ANIMATIONS_ANIMATION_H

class Animation {
public:
  virtual ~Animation() {}
  virtual int play() { return 0; }
};

#endif