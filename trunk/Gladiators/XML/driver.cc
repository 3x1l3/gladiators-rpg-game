#include<iostream>
#include "pugixml.h"
#include "XMLWrapper.h"
#include "ConvertData.h"

int main() {

  XMLWrapper test("sampleSave.xml");
  test.LoadSaveFile();
  std::cout << test.getCharacterVector()[0][5];
  return 0;
}
