#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Global.hh"

class Player
{
public:
    Player(std::string jumpFile, std::string idleFile, std::string runFile, std::string deathFile, std::string crouchFile, float switchTime);
    Player();
    ~Player();

    void update(float deltaTime, unsigned int width, unsigned int height);

    void setSpeed(float speed);
    void notMoving();

    float getSpeed();
    sf::Vector2f getPos();

    void levelBoundary(unsigned int width, unsigned int height);

    void move(sf::Vector2f direction);
    void jump();

    void draw(sf::RenderWindow &window);

private:
    sf::Texture jumpTexture;
    sf::Texture idleTexture;
    sf::Texture runTexture;
    sf::Texture deathTexture;
    sf::Texture crouchTexture;

    sf::Texture* currentTexture = nullptr;
    std::vector<sf::IntRect> currectVector = Global::idleAnimations;
    size_t animationIndex = 0;
    sf::Sprite playerSprite;
    sf::Vector2f scale = {3.f, 3.f};

    void setIdle();

    float switchTime;
    float totalTime = 0.f;

    bool isMoving = false;
    bool OnAir = false;

    sf::Vector2f pos;

    float speed = 1.f;
    float jumpHeight = 60.f;
    float jumpSpeed = 1.f;

    int health, armour, energy, coins = 0;
};