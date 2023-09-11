package hero;
import weapon.*;
import fly.*;

public abstract class Heroes implements Ifly,Iweapon {
	Iweapon weapon;
	Ifly fly;
	void run() {};
	void display() {};
	void hasWeapon() {};
	void canFly() {};
	void setWEapon() {};
	void setFly() {};
	
}
