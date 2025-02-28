// #include "TerminalDisplay.hpp"

// void TerminalDisplay::displayAnthillRoomInfo(string roomName, int capacity, vector<string> tunnelNames){
//     cout << ">Rooms Information " << endl;

//     cout << ">Room: " << roomName << endl;
//     cout << ">Capacity: " << capacity << endl;
    
//     cout << "\n>Connections Information: " << endl;
//     for (string tunnel : tunnelNames) {
//         cout << "Room: " << roomName
//              << " is connected to: " << tunnel << endl;
//     }        
//     // cout << "\n> Start Room: "<< endl;
//     // cout << ">End Room: " << endl;   
// } 

// void TerminalDisplay::displayAnthillAntInfo(string antName, int id, string currentRoom){
//     cout << "Hello i'm Ant " << id << ", Start Room: " << currentRoom << endl;
// }

// // void TerminalDisplay::displayAnthillInfo(int anthillNumber) {
// //     json data = dataManager.getAnthillData(anthillNumber);

// //     if (data.empty()) {
// //         cout << "No information found for the selected anthill.\n";
// //         return;
// //     }

// //     cout << "ANTHILL INFORMATION:" << endl;

// //     cout << "> Rooms Information " << endl;
// //     for (const auto& room : data["rooms"]) {
// //         cout << "Room: " << room["name"]
// //              << ", Capacity: " << (room["capacity"] == -1 ? "Unlimited" : to_string(room["capacity"]))
// //              << endl;
// //     }

// //     cout << "\n> Start Room: " << data["startRoom"] << endl;
// //     cout << "> End Room: " << data["endRoom"] << endl;

// //    cout << "\n> Ants Information " << endl;
// //     for (const auto& ant : data["ants"]) {
// //         cout << "Ant " << ant["id"] << ", Start Room: " << ant["startRoom"] << endl;
// //     }

// //     cout << "\n> Connections Information: " << endl;
// //     for (const auto& room : data["rooms"]) {
// //         for (const auto& tunnel : room["tunnels"]) {
// //             cout << "Room: " << room["name"]
// //                  << " is connected to: " << tunnel["name"] << endl;
// //         }
// //     }
// // }

