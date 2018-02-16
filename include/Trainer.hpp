//
// Trainer.hpp for trainer in /home/guillaume2.roux/Perso/PkmnGame/include/
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Sat Sep  2 22:48:02 2017 Guillaume Roux
// Last update Mon Sep  4 19:01:36 2017 Guillaume Roux
//

#ifndef TRAINER_HPP
# define TRAINER_HPP

# include <iostream>
# include <list>
# include "APokemon.hpp"

class Trainer
{
private:
  std::string _name;
  std::list<Pokemon> _pkmn;

public:
  Trainer(std::string const name = "") {
    this->_name = name;
  };
  virtual ~Trainer(){};

  Pokemon & getPokmn(int pos) {
    std::list<Pokemon>  *it = new std::list<Pokemon> (this->_pkmn);

    for (int i = 0; i < pos; i++)
      it->pop_front();
    return it->front();
  };

  std::list<Pokemon> getPokmn() const {
    return this->_pkmn;
  }

  void  addPkmn(Pokemon const & pkmn) {
    if (this->_pkmn.size() < 6) {
      this->_pkmn.push_front(pkmn);
      std::cout << pkmn.getName() << " is added to your party !" << std::endl;
    }
    else
      std::cout << "Your party is full !" << std::endl;
  };

  std::string getName() const {
    return this->_name;
  };

  void  setName(std::string const &name) {
    this->_name = name;
  };
};
Trainer player;

#endif
