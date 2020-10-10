#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"


int main(){
  std::string cmd;
  Polygon* shapes[100];
  int shapesCount = 0;
  while(true) {
    std::cout << "Menu:\n"
              << "1) Create a shape\n"
              << "2) Browse shapes\n"
              << "3) Move a shape\n"
              << "4) Compare areas of two shapes\n"
              << "5) Exit\n"
              << "Command: ";
    std::cin >> cmd;
    if (cmd == "1") {
      std::cout << "1) Triangle\n"
                << "2) Rectangle\n"
                << "3) Cancel\n"
                << "Command: ";
      std::cin >> cmd;
      while(not (cmd =="1" or cmd=="2" or cmd=="3")){
        std::cout << "Wrong command." << std::endl;
      }
      if(cmd=="1"){
        std::cout << "Enter three points in format\n" << "1 2\n" << "3 4\n" << "5 6\n" << "Points:\n";
        Point* points[3];
        for(int i=0;i<3;i++){
          double x,y;
          scanf("%lf %lf",&x,&y);
          points[i] = new Point(x,y);
        }
        std::string id;
        std::cout << "Enter an ID for your new polygon: ";
        std::cin >> id;
        shapes[shapesCount] = new Triangle(id,points[0],points[1],points[2]);
        shapesCount+=1;
      }else if(cmd=="2"){
        std::cout << "Enter top left and bottom right point in format\n" << "0 0\n" << "-3 3\n" << "Points:\n";
        double x1,x2,y1,y2;
        scanf("%lf %lf",&x1,&y1);
        scanf("%lf %lf",&x2,&y2);
        while(not (x1<x2 and y1>y2) ){
          std::cout << "Wrong position!";
          scanf("%lf %lf",&x1,&y1);
          scanf("%lf %lf",&x2,&y2);
        }
        std::string id;
        std::cout << "Enter an ID for your new polygon: ";
        std::cin >> id;
        shapes[shapesCount] = new Rectangle(id,Point(x1,y1),Point(x2,y2));
        shapesCount+=1;
      }
    } else if (cmd == "2") {
      std::cout << "Your shapes(" << shapesCount << "/100):\n";
      for(int i=0;i<shapesCount;i++){
        std::cout << shapes[i]->getType() << " \"" << shapes[i]->getId() << "\" with area " << shapes[i]->getArea() << " at position " << shapes[i]->getPos()->getX() << " " << shapes[i]->getPos()->getY() << "\n";
      }
    } else if (cmd == "3") {
      std::cout << "Choose a shape to move:\n";
      for(int i=0;i<shapesCount;i++){
        std::cout << i+1 << ") " << shapes[i]->getType() << " \"" << shapes[i]->getId() << "\" with area " << shapes[i]->getArea() << " at position " << shapes[i]->getPos()->getX() << " " << shapes[i]->getPos()->getY() << "\n";
      }
      std::cin >> cmd;
      int id=std::stoi(cmd);
      while(id-1>=shapesCount or id-1<0){
        std::cout << "Wrong id!";
        std::cin >> cmd;
        int id=std::stoi(cmd);
      }
      std::cout << "Enter x and y for move (format: 1 3): ";
      double x,y;
      scanf("%lf %lf",&x,&y);
      shapes[id-1]->Move(x,y);
    } else if (cmd == "4") {
      std::cout << "Choose first shape to compare:\n";
      for(int i=0;i<shapesCount;i++){
        std::cout << i+1 << ") " << shapes[i]->getType() << "\"" << shapes[i]->getId() << "\" with area " << shapes[i]->getArea() << " at position " << shapes[i]->getPos()->getX() << " " << shapes[i]->getPos()->getY() << "\n";
      }
      std::cin >> cmd;
      int id=std::stoi(cmd);
      while(id-1>=shapesCount or id-1<0){
        std::cout << "Wrong id!";
        std::cin >> cmd;
        int id=std::stoi(cmd);
      }
      Polygon* first = shapes[id-1];
      std::cout << "Choose second shape to compare:\n";
      for(int i=0;i<shapesCount;i++){
        std::cout << i+1 << ") " << shapes[i]->getType() << "\"" << shapes[i]->getId() << "\" with area " << shapes[i]->getArea() << " at position " << shapes[i]->getPos()->getX() << " " << shapes[i]->getPos()->getY() << "\n";
      }
      std::cin >> cmd;
      id=std::stoi(cmd);
      while(id-1>=shapesCount or id-1<0){
        std::cout << "Wrong id!";
        std::cin >> cmd;
        int id=std::stoi(cmd);
      }
      Polygon* second = shapes[id-1];
      int result = first->Compare(*second);
      if(result==1){
        std::cout << "First shape is larger!\n";
      }else if(result==0){
        std::cout << "The shapes are equal!\n";
      }
      else{
        std::cout << "Second shape is larger!\n";
      }
    } else if (cmd == "5") {
      break;
    }
    else{
      std::cout << "Wrong command." << std::endl;
    }
  }
  return 0;
}