## definitions
CC = g++
CCFLAGS = -Wall -g
# Path to CPPUNIT on J.Racine's machine
CPPUNIT_PATH = /usr
OBJS1 = Mansbridge.o Archer.o Armor.o BattleMenu.o BackstageMenu.o BattleEvent.o BattleNumber.o CharacterCreationMenu.o Commoner.o Consumable.o ConvertData.o Dead.o EditCharacterMenu.o EnemyCharacter.o EnemyParty.o Equipable.o Game.o GameData.o Item.o Job.o Menu.o Money.o Normal.o Paladin.o PlayerCharacter.o PlayerParty.o PotionItem.o pugixml.o State.o StoreMenu.o StoryEvent.o Unit.o UnitEquipment.o Weapon.o Wizard.o XMLWrapper.o

## targets and prerequisites
.PHONY : all
all : Mansbridge

Mansbridge: $(OBJS1)

prog1 : $(OBJS1)
	$(CC) $^ -o $@
     
prog2 : $(OBJS2)
	$(CC) $^ -o $@

prog3 : $(OBJS3)
	$(CC) $^ -o $@

cppunit : WizardTester.o UnitEquipmentTester.o TestRunner.cc Archer.o Armor.o BattleMenu.o BackstageMenu.o BattleEvent.o BattleNumber.o CharacterCreationMenu.o Commoner.o Consumable.o ConvertData.o Dead.o EditCharacterMenu.o EnemyCharacter.o EnemyParty.o Equipable.o Game.o GameData.o Item.o Job.o Menu.o Money.o Normal.o Paladin.o PlayerCharacter.o PlayerParty.o PotionItem.o pugixml.o State.o StoreMenu.o StoryEvent.o Unit.o UnitEquipment.o Weapon.o Wizard.o XMLWrapper.o
	$(CC) $^ -L${CPPUNIT_PATH} -lcppunit -ldl -o $@

# default rule for compiling .cc to .o
%.o: %.cc                               ## next line must begin with a TAB
	$(CC) -c $(CCFLAGS) $<
 

## generate the prerequistes and append to the desired file
.prereq : $(OBJS1:.o=.cc) $(OBJS2:.o=.cc) $(OBJS3:.o=.cc) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS1:.o=.cc) $(OBJS2:.o=.cc) $(OBJS3:.o=.cc) >> ./.prereq 

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :                 ## next lines must begin with a TAB
	rm -f *.o
	rm -f *~ *# .#*

.PHONY : clean-all
	clean-all : clean      ## next line must begin with a TAB
	rm -f Mansbridge
