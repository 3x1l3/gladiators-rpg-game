#include<vector>
#include<string>
#include "Party.h"
#include "Inventory.h"
#include "Unit.h"
#include "Item.h"

class ConvertData {

 private:
  std::vector<std::vector<int> > items;
  std::vector<std::vector<std::string> > characters;
  Party* party;
  Inventory* weapons;
  Inventory* armor;
  Inventory* consumable;

 public:
  ConvertData(std::vector<std::vector<int> >, std::vector<std::vector<std::string> >);
  void Run();
  void BuildParty();
  Inventory* BuildWeapons(const Inventory*);
  Inventory* BuildArmor(const Inventory*);
  Inventory* BuildConsumables(const Inventory*);
  Party* getParty();
  Inventory* getWeapons();
  Inventory* getArmor();
  Inventory* getConsumables();


};
