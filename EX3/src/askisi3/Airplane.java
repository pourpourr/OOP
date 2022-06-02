package askisi3;

import java.util.concurrent.ThreadLocalRandom;
import java.util.*;

public class Airplane {
	
	private int numOfpassengers,cabins;
	private Vector <PassengerCompartment> pass;
	private Vector <CargoBay> car;
	private EquipmentCompartment equip;
	
	Airplane(){
		
		numOfpassengers=ThreadLocalRandom.current().nextInt(20,300);
		cabins =ThreadLocalRandom.current().nextInt(2,5 );
		pass= new Vector<PassengerCompartment>();
		car= new Vector<CargoBay>();
		for (int i=0 ; i<cabins; i++) {
			
			if (i+1 != cabins) {
				pass.add(new PassengerCompartment(numOfpassengers/cabins));
			}else {
				pass.add(new PassengerCompartment(numOfpassengers/cabins+numOfpassengers%cabins));
			}
		
		}
		
		for (int i=0 ; i<3; i++) {
			
			car.add(new CargoBay());
		
		}
		
		equip = new EquipmentCompartment();
		
		
	}


	public boolean ready_check(){
	    boolean ready=true;
	    int i;
	    for(i=0; i<cabins; i++){

	      ready=ready&&pass.get(i).ready_check();
	    }
	    for (i=0; i<3; i++){
	      ready=ready&&car.get(i).ready_check();
	    }
	    ready=ready&&equip.ready_check();
	    System.out.println(this.toString());
	    if(ready){
	    	System.out.println("plane ready for take-off \n");
	    }else{
	    	System.out.println("plane not ready for take-off \n");
	    }
	    return ready;

	}
	
	public String toString(){
	    int i;
	    String str= "\n ===|Airplane|=== \n"+ "numOfpassengers_"+String.valueOf(numOfpassengers)+"\n"+"cabins: "+String.valueOf(cabins)+"\n";
	    for(i=0; i<cabins; i++){

	      str=str+pass.get(i).toString();
	    }
	    for (i=0; i<3; i++){
	      str=str+car.get(i).toString();
	    }
	    str=str+ equip.toString();
	    return str;
	}
	
	public void process(MaintenanceEmployee Maintenance){

	    int i;
	    for(i=0; i<cabins; i++){

	      pass.get(i).process(Maintenance);
	    }
	    for (i=0; i<3; i++){
	      car.get(i).process(Maintenance);
	    }
	    equip.process(Maintenance);

	}
	
	public void process(CleaningEmployee Cleaning){

	    int i;
	    for(i=0; i<cabins; i++){

	      pass.get(i).process(Cleaning);
	    }
	    for (i=0; i<3; i++){
	      car.get(i).process(Cleaning);
	    }
	    equip.process(Cleaning);

	}
	
	public void process(SecurityEmployee Security){

	    int i;
	    for(i=0; i<cabins; i++){

	      pass.get(i).process(Security);
	    }
	    for (i=0; i<3; i++){
	      car.get(i).process(Security);
	    }
	    equip.process(Security);

	}
	
	public int getNumOfpassengers() {
		return numOfpassengers;
	}

	public int getCabins() {
		return cabins;
	}

	public PassengerCompartment getPass(int pos) {
		return pass.get(pos);
	}

	public CargoBay getCar(int pos) {
		return car.get(pos);
	}

	public EquipmentCompartment getEquip() {
		return equip;
	}
	
	
}
