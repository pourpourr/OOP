package askisi3;

abstract public class Employee {
	
	protected String name;
	protected int state;
	
	Employee(String n){
		state=0;
		this.name=n;
		
	}
	
	public  int report() {
		
		switch (state) {
	      case 0:
	        System.out.println("no work \n");
	        break;
	      case 1:
	        System.out.println("epevlepsa \n");

	        break;
	      case 2:
	    	System.out.println("syntirisa \n");

	        break;
	      case 3:
	        System.out.println("katharisa \n");

	        break;

	      }
	      return state;
	}
	
	public abstract void workOn(PassengerCompartment Pass);
	
	public abstract void workOn(CargoBay Cargo) ;
	
	public abstract void workOn(EquipmentCompartment Equip) ;
	
	public String toString() {
		
		  String str = "|Employee|\n"+"\n"+"name:"+name+"\n"+"state:"+String.valueOf(state);
		  return str;
		
	}

	public String getName() {
		return name;
	}
	
	
}

class SecurityEmployee extends Employee{

	SecurityEmployee(String n){
		super(n);
		
		
	}
	
	public void workOn(PassengerCompartment Pass) {
		state=1;
	}
	
	public void workOn(CargoBay Cargo) {
		state=1;

	}
	
	public void workOn(EquipmentCompartment Equip) {
		state=1;

	}

	public  int report() {
		
		System.out.println("I the securitas \t");
		return super.report();
		
	}
	
}

class MaintenanceEmployee extends Employee{

	MaintenanceEmployee(String n){
			super(n);
			
	}
	
	public void workOn(PassengerCompartment Pass) {
		
	}
	
	public void workOn(CargoBay Cargo) {
	    state=2;

	}
	
	public void workOn(EquipmentCompartment Equip) {
	    state=2;

	}

	public  int report() {
		System.out.println("I the Maintenant \t");
		return super.report();
	}
	
}

class CleaningEmployee extends Employee{
	
	CleaningEmployee(String n){
		super(n);
	
	}

	public void workOn(PassengerCompartment Pass) {
	    state=3;

	}
	
	public void workOn(CargoBay Cargo) {
	    state=3;

	}
	
	public void workOn(EquipmentCompartment Equip) {
		
	}

	public  int report() {
		System.out.println("I the Cleaner \t");
		return super.report();
	}
	
}