#pragma once

#include "Deck.h"
#include "Card.h"
#include <iostream>

void initializeDeck(Deck &deck) {
    deck.addCard(Card(1, "Poporul vrea taxe mai mici!", "Scade taxele", "Refuza", {-10,+5,0,-5}, {+10,-5,0,+5}));
    deck.addCard(Card(2, "Biserica cere o donatie", "Doneaza", "Refuza", {+5,-5,0,-10}, {-5,+5,0,0}));
    // ID 3: Criza alimentara
    deck.addCard(Card(3, "Seceta ameninta recolta de grau. Ce faci?",
                     "Importa hrana (-Bani, +Popor)", "Pune ratii la populatie (-Popor, +Armata)",
                     {0, +10, 0, -15}, {0, -15, +5, 0}));

    // ID 4: Rebelii se aduna
    deck.addCard(Card(4, "Au aparut zvonuri despre o rascoala la granita de vest.",
                     "Trimite Armata (-Bani, -Popor)", "Ignora (risc mare)",
                     {0, -10, +5, -10}, {0, -20, 0, 0}));

    // ID 5: Proiect de infrastructura
    deck.addCard(Card(5, "Negustorii cer un pod nou peste rau.",
                     "Accepta (-Bani)", "Refuza (impact Popor)",
                     {0, +5, 0, -15}, {0, -5, 0, +5}));

    // ID 6: Edict religios
    deck.addCard(Card(6, "Patriarhul cere ca toate cartile neortodoxe sa fie arse.",
                     "Accepta (+Biserica, -Popor)", "Refuza (+Popor, -Biserica)",
                     {+10, -5, 0, 0}, {-5, +10, 0, 0}));

    // ID 7: Inundatii in capitala
    deck.addCard(Card(7, "O mare inundatie loveste capitala. E nevoie de efort.",
                     "Mobilizeaza Armata (-Armata)", "Cere ajutor de la Biserica (-Biserica)",
                     {0, 0, -5, -5}, {+5, 0, 0, -5}));

    // ID 8: Oportunitate de comert
    deck.addCard(Card(8, "Un imperiu vecin ofera un tratat de comert avantajos.",
                     "Accepta (+Bani, +Popor)", "Refuza (risc de spionaj)",
                     {0, +5, 0, +15}, {0, 0, 0, 0}));

    // ID 9: Biserica vrea putere
    deck.addCard(Card(9, "Preotii vor ca judecatile sa fie facute in biserici.",
                     "Accepta (+Biserica, -Armata)", "Refuza (+Armata, -Biserica)",
                     {+15, 0, -10, 0}, {-10, 0, +5, 0}));

    // ID 10: Epidemie usoara
    deck.addCard(Card(10, "O boala noua dar usoara afecteaza satele din nord.",
                      "Izoleaza satele (-Popor)", "Trimite doctori (-Bani)",
                      {0, -5, 0, 0}, {0, 0, 0, -5}));

    // ID 11: Sarbatoare nationala
    deck.addCard(Card(11, "Pentru a ridica moralul, o sarbatoare de 3 zile este propusa.",
                      "Aproba (-Bani, +Popor)", "Refuza (economia e importanta)",
                      {0, +10, 0, -10}, {0, -5, 0, +5}));

    // ID 12: Mercenari
    deck.addCard(Card(12, "Un grup de mercenari excelenti ofera serviciile lor.",
                      "Angajeaza-i (+Armata, -Bani)", "Refuza",
                      {0, 0, +15, -20}, {0, 0, 0, +5}));

    // ID 13: Vandalism bisericesc
    deck.addCard(Card(13, "Simboluri sacre au fost vandalizate in capitala.",
                      "Pedeapsa aspra (+Biserica, -Popor)", "Iertare publica (-Biserica, +Popor)",
                      {+10, -10, 0, 0}, {-5, +5, 0, 0}));

    // ID 14: Inventie noua
    deck.addCard(Card(14, "Un inventator afirma ca poate imbunatati productia.",
                      "Finanteaza-l (-Bani, +Popor)", "Ignora (risc)",
                      {0, +5, 0, -10}, {0, 0, 0, 0}));

    // ID 15: Cerere de titluri
    deck.addCard(Card(15, "Nobilii cer titluri si pamanturi noi.",
                      "Accepta (+Biserica, -Bani)", "Refuza (risc rascoala nobili)",
                      {+5, 0, 0, -5}, {0, -5, 0, 0}));

    // ID 16: Confruntare la hotar
    deck.addCard(Card(16, "O mica ciocnire a avut loc la frontiera de est.",
                      "Contra-ataca (+Armata, -Bani)", "Retrage trupele",
                      {0, 0, +5, -10}, {0, 0, -5, +5}));

    // ID 17: Fuga in masa
    deck.addCard(Card(17, "Oamenii fug din provincia saraca in cautare de munca.",
                      "Ofera ajutor social (-Bani, +Popor)", "Inchide granita",
                      {0, +5, 0, -10}, {0, -10, +5, 0}));

    // ID 18: Recolta exceptionala
    deck.addCard(Card(18, "Recolta a fost neasteptat de bogata.",
                      "Exporta surplusul (+Bani)", "Redistribuie populatiei (+Popor)",
                      {0, 0, 0, +15}, {0, +15, 0, 0}));

    // ID 19: Lider militar corupt
    deck.addCard(Card(19, "Se stie ca un General fura fonduri din armata.",
                      "Inlocuieste-l (+Armata, +Bani)", "Il lasi (stii ca e loial)",
                      {0, 0, +10, +10}, {0, 0, -5, 0}));

    // ID 20: Pacea cu vecinii
    deck.addCard(Card(20, "Vecinii propun o alianta de pace pe termen lung.",
                      "Accepta (-Armata, +Popor)", "Refuza (pregateste-te de razboi)",
                      {0, +10, -10, 0}, {0, -5, +5, 0}));

    // ID 21: Donatie secreta
    deck.addCard(Card(21, "Biserica ofera o donatie mare la cuferele regale in schimbul unui favor.",
                      "Accepta (+Bani, +Biserica)", "Refuza",
                      {+5, 0, 0, +10}, {0, 0, 0, 0}));

    // ID 22: Muncitori straini
    deck.addCard(Card(22, "Muncitori straini vin in regat pentru a lucra in mine.",
                      "Accepta (+Bani, -Popor local)", "Interzice-le accesul (+Popor local)",
                      {0, -5, 0, +10}, {0, +5, 0, 0}));

    // ID 23: Disputa funciara
    deck.addCard(Card(23, "Doi nobili se bat pe o bucata de pamant. Tu trebuie sa decizi.",
                      "Decide in favoarea primului (+Bani)", "Imparte pamantul (+Popor)",
                      {0, -5, 0, +5}, {0, +5, 0, 0}));

    // ID 24: Arme noi
    deck.addCard(Card(24, "Un fierar local a inventat un tip nou de arma.",
                      "Finanteaza productia (+Armata, -Bani)", "Nu risti (-Armata)",
                      {0, 0, +10, -10}, {0, 0, -5, +5}));

    // ID 25: Calamitate naturala
    deck.addCard(Card(25, "Cutremur in zona agricola. Pierderi mari.",
                      "Ajuta populatia (-Bani)", "Cere Bisericii sa se roage (-Biserica)",
                      {0, 0, 0, -10}, {-5, 0, 0, 0}));

    // ID 26: Crestere demografica
    deck.addCard(Card(26, "Rata natalitatii a explodat. Populatia creste rapid.",
                      "Impoziteaza nasterile (+Bani, -Popor)", "Investeste in educatie (+Popor, -Bani)",
                      {0, -10, 0, +15}, {0, +10, 0, -10}));

    // ID 27: Propaganda militara
    deck.addCard(Card(27, "Se propune o campanie de propaganda pentru a ridica moralul armatei.",
                      "Aproba (-Bani, +Armata)", "Refuza",
                      {0, 0, +5, -5}, {0, 0, 0, 0}));

    // ID 28: Erezii
    deck.addCard(Card(28, "Un nou cult se raspandeste. Biserica cere sa fie interzis.",
                      "Interzice-l (+Biserica, -Popor)", "Permite-l (-Biserica, +Popor)",
                      {+10, -10, 0, 0}, {-10, +10, 0, 0}));

    // ID 29: Coruptie
    deck.addCard(Card(29, "Se descopera o retea de coruptie in randul oficialilor.",
                      "Investigheaza (-Bani, +Popor)", "Musamalizeaza (-Popor, +Biserica)",
                      {0, +15, 0, -15}, {+5, -10, 0, 0}));

    // ID 30: Nevoie de lemn
    deck.addCard(Card(30, "Avem nevoie de lemn pentru constructii navale.",
                      "Taie padurile statului (+Bani, -Popor)", "Cumpara de la vecini (-Bani)",
                      {0, -10, 0, +10}, {0, 0, 0, -10}));

    // ID 31: Razboiul vecinului
    deck.addCard(Card(31, "Un regat vecin intra in razboi. Ar trebui sa ne implicam?",
                      "Trimite ajutor (+Bani, +Armata)", "Declara neutralitate (-Popor)",
                      {0, -5, +5, -10}, {0, -10, 0, 0}));

    // ID 32: Taxe pentru Biserica
    deck.addCard(Card(32, "Biserica cere sa nu mai plateasca taxe la stat.",
                      "Accepta (+Biserica, -Bani)", "Refuza (+Bani, -Biserica)",
                      {+10, 0, 0, -10}, {-10, 0, 0, +10}));
}