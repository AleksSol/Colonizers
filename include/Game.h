#pragma once
#include "Player.h"
#include "Field.h"
#include <vector>
#include <stdexcept>
#include <memory>
class Game 
{
    std::unique_ptr<Field> _field;
    std::vector<std::unique_ptr<Player>> _players;
    Game (const Game &) = delete;
    Game &operator= (const Game &) = delete;
public:
    Game();                                         //– создает объект поля без обьектов игроков
    ~Game();                                        //- удаляет объект поля и объекты игроков
    Field &field() const noexcept;                  //– возвращает ссылку на объект поля (ссылка позволяет модифицировать объект поля даже в случае константного объекта игры)
    Player &add_player(const std::string &);        //- добавить игрока с указанным именем, возвратить созданного игрока
    size_t num_players() const noexcept;            //– возвращает количество игроков в игре
    Player &player(size_t i) const;                 //– возвращает игрока под номером i. i принимает значения от 0 до num_players()-1. При других значениях i  должна возникнуть исключительная ситуация std::out_of_range с непустым информативным сообщением. 

};


