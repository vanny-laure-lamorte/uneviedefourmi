#include "Anthill.hpp"
#include "AntManager.hpp"


Anthill::Anthill(const std::vector<std::shared_ptr<Room>>& roomsList,
    const std::vector<Ant>& antsList,
    std::shared_ptr<Room> Sv,
    std::shared_ptr<Room> Sd,
    int step)
: anthillRoomsList(roomsList), anthillAntsList(antsList), Sv(Sv), Sd(Sd), step(step)
{}

void Anthill::displayAnthillInfo() const {
    cout << "\n>Rooms Information:\n";
    for (auto& room : anthillRoomsList) {
        cout << "Room: " << room->getName()
             << ", Capacity: " << (room->getCapacity() == -1 ? "Unlimited" : to_string(room->getCapacity()))
             << endl;
    }

    cout << "\n>Start Room: " << Sv->getName() << endl;
    cout << ">End Room: " << Sd->getName() << endl;

    cout << "\n>Ants Information:\n";
    for (auto& ant : anthillAntsList) {
        cout << "Ant " << ant.getId() << ", Start Room: " << ant.getCurrentRoom()->getName() << endl;
    }

    cout << "\n>Connections Information:\n";
    for (auto& room : anthillRoomsList) {
        for (auto& tunnel : room->getTunnels()) {
            cout << "Room: " << room->getName()
                 << " is connected to: " << tunnel->getName() << endl;
        }
    }
}

std::shared_ptr<Room> Anthill::findRoomByName(const std::string& roomName) {
    for (auto& room : anthillRoomsList) {
        if (room->getName() == roomName) {
            return room;
        }
    }
    return nullptr;
}

void Anthill::moveAntsWithManager() {
    AntManager manager(anthillAntsList, Sv, Sd);
    manager.assignPaths();
    manager.moveAntsStepByStep();
}

bool Anthill::isValid() const {
    return Sv && Sd && !anthillRoomsList.empty() && !anthillAntsList.empty();
}

void Anthill::displayAntLocationStepByStep() {
    // If all ants are already at the end, skip the loop
    bool alreadyAtEnd = true;
    for (const Ant& ant : anthillAntsList) {
        if (ant.getCurrentRoom() != Sd) {
            alreadyAtEnd = false;
            break;
        }
    }

    if (alreadyAtEnd) {
        std::cout << "\n✅ All ants are already at the end room!\n";
        return;
    }

    AntManager manager(anthillAntsList, Sv, Sd);
    manager.assignPaths();
    manager.moveAntsStepByStep();
}
