#include <stdio.h>

struct ent{
  char* name;
  int mHP;
  int HP;
  int attack;
  int defence;
  int blocking;
};
typedef struct ent Entity;

Entity new(char* name, int HP, int mHP, int attack, int defence){
  Entity enew;
  enew.name = name;
  enew.mHP = mHP;
  enew.HP = HP;
  enew.attack = attack;
  enew.defence = defence;
  enew.blocking=0;
  return enew;
}

int alive(Entity persona){
  return persona.HP > 0;
}

void announce(Entity persona){
  if(persona.HP == persona.mHP){
    printf("%s has full health, "\
	"%i strength, and armour class %i\n",\
 	persona.name, persona.attack, persona.defence);
  }
  else{
    printf("%s has %i/%i health, %i strength, and armour class %i\n",\
    	persona.name, persona.HP, persona.mHP, persona.attack, persona.defence);
  }
}

void strike(Entity attacker, Entity *defender){

  printf("  %s attacks %s!\n",attacker.name,(*defender).name);
  
  int damage;
  if((*defender).blocking){
    printf("  - %s deflects %i damage.\n",(*defender).name, (*defender).defence);
    damage = (*defender).defence > attacker.attack ?\
    0 : attacker.attack-(*defender).defence;
  }
  else
    damage = attacker.attack;
  
  (*defender).HP = damage > (*defender).HP ?\
  0 : (*defender).HP - damage;
  
  printf("  - %s does %i damage to %s!\n",attacker.name, damage, (*defender).name);
  printf("  - %s is %s\n\n",(*defender).name,\
  alive(*defender) ?
  "still alive." : "dead!");
  
}

void ai_think(Entity *ai){

  int nowHP = (*ai).HP;
  int criticalHP = (*ai).mHP/3;
  
  if (nowHP <= criticalHP){
    (*ai).blocking = 1;
    printf("  %s raises shield.\n",(*ai).name);
  }
  else{
    (*ai).blocking = 0;
  }
}

int main(){
  Entity player,enemy;
  
  player = new("Ste",20,20,3,1);
  enemy = new("Troll", 15,15,2,2);
  
  while (alive(player) && alive(enemy)){
    announce(player);
    announce(enemy);
    int valid=0;
    
    while(!valid){ 
      printf("Will you [A]ttack or [B]lock?\n");
      char command=getchar();
      switch(command){
        case 'a':
        case 'A':
          ai_think(&enemy);
          strike(player,&enemy);
          valid=1;
          break;
        case 'b':
        case 'B':
          ai_think(&enemy);
          player.blocking=1;
          printf("  %s raises shield.\n",player.name);
          valid=1;
          break;
        default:
            printf("  No; press A or B.\n");
      }
      getchar();
      if(!enemy.blocking){
        strike(enemy,&player);
      }
    }
    
  }
  if (alive(enemy))
    printf("You have lost the battle, and have died.");
  else
    printf("You have overcome the %s!\n\
The name, \"%s\" will feature in the songs of villagefolk for years to come.\n",\
    enemy.name, player.name);

  return 0;
}

