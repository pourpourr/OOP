package askisi3;

import java.util.concurrent.ThreadLocalRandom;

abstract public class PlaneComponent {
	
	PlaneComponent(){
		
	}
	
	public abstract String toString() ;
	
	public abstract void process(SecurityEmployee Security) ;
		
	
	public abstract void process(CleaningEmployee Cleaning) ;
	
	public abstract void process(MaintenanceEmployee Maintenance) ;
	

}

class PassengerCompartment extends PlaneComponent{
	
	private static int luck=0;
	private boolean flagC,flagS;
	private int people;
	private PassengerCompartment internalSpace;
	
	PassengerCompartment(int num){
		super();
		flagC=false;
		flagS=false;
		luck++;
		if (luck%3==0) {
			people=ThreadLocalRandom.current().nextInt(1,num );
			internalSpace= new PassengerCompartment(num-people);
		}else {
			people= num;
			internalSpace= null;
		}
	}

	public void process(SecurityEmployee Security) {
		Security.workOn(this);
	    if(internalSpace!=null) {
	      internalSpace.process(Security);
	    }
	    if (Security.report()==1){
	      flagS= true;
	    }
	}
	public void process(CleaningEmployee Cleaning) {
    	Cleaning.workOn(this);
	    if(internalSpace!=null) {
	        internalSpace.process(Cleaning);
	    }
	    if(Cleaning.report()==3){
	      flagC=true;
	    }
    }
    public void process(MaintenanceEmployee Maintenance) {
    	
    }
	
	public String toString() {
		String str;
		  if(internalSpace!=null){
		    str ="\n |PassangerCompartment| \n"+"people:"+String.valueOf(people)+"\n"+"luck:"+String.valueOf(luck)+"\n"+"flagC:"+String.valueOf(flagC)+"\n"+"flagS:"+String.valueOf(flagS)+"\n"+"\t ***internalSpace***"+internalSpace.toString();
		  }else{
			str ="\n |PassangerCompartment| \n"+"people:"+String.valueOf(people)+"\n"+"luck:"+String.valueOf(luck)+"\n"+"flagC:"+String.valueOf(flagC)+"\n"+"flagS:"+String.valueOf(flagS)+"\n";

		  }
		  
		  return str;

	}

    public boolean ready_check() {
    	boolean temp;
    	if(internalSpace==null){
    	      temp= flagC&&flagS;
    	  }else{
    		  temp= flagC&&flagS&&internalSpace.ready_check();
    	  }
    	
    	if(temp) {
    	    System.out.println( "PassengerCompartment  OK! \n" );
    	}
    	else {
    	    System.out.println( "PassengerCompartment not OK! \n" );
    	}
    	return temp;
    }

	public static int getLuck() {
		return luck;
	}

	public boolean isFlagC() {
		return flagC;
	}

	public boolean isFlagS() {
		return flagS;
	}

	public int getPeople() {
		return people;
	}

	public PassengerCompartment getInternalSpace() {
		return internalSpace;
	}
    
    
}

abstract class PrivateCompartment extends PlaneComponent {
	
	PrivateCompartment(){
		super();
		
	}
	
	public abstract String toString() ;
	
	public abstract void process(SecurityEmployee Security) ;
		
	
	public abstract void process(CleaningEmployee Cleaning) ;
	
	public abstract void process(MaintenanceEmployee Maintenance) ;
}

class EquipmentCompartment extends PrivateCompartment{
	
	private boolean flagM,flagS;
	
	EquipmentCompartment(){
		super();
		flagS=false;
	    flagM=false;
	}
	
	public void process(SecurityEmployee Security) {
		
		Security.workOn(this);
	    if (Security.report()==1){
	      flagS= true;
	    }

	}
	
	public void process(MaintenanceEmployee Maintenance) {
		
		Maintenance.workOn(this);
	    if(Maintenance.report()==2){
	      flagM=true;
	    }
	}
	
	public void process(CleaningEmployee Cleaning) {
		
		
	}
	
	
	public String toString() {
		
		String str ="\n |EquipmentCompartment| \n" + "flagM:"+String.valueOf(flagM)+"\n"+"flagS:"+String.valueOf(flagS);
		return str;
	}


	public boolean isFlagM() {
		return flagM;
	}
	
	

	public boolean isFlagS() {
		return flagS;
	}
	
	boolean ready_check(){
	    boolean temp= flagM&&flagS;
	    if(temp) {
	      System.out.println( "EquipmentCompartment OK! \n");
	    }
	    else {
		   System.out.println( "EquipmentCompartment not OK! \n");
	    }
	    return temp;
	}
}	


class CargoBay extends PrivateCompartment{
	
	private boolean flagC,flagM,flagS;
	
	private EquipmentCompartment internalEquip;
	
	CargoBay(){
		
		super();
		flagC=false;
		flagM=false;
		flagS=false;
		internalEquip= new EquipmentCompartment();
		
	}	
	
	public void process(SecurityEmployee Security) {
		
		Security.workOn(this);
	    internalEquip.process(Security);
	    if (Security.report()==1){
	      flagS= true;
	    }
		
	}
	
    public void process(CleaningEmployee Cleaning){
    	
    	Cleaning.workOn(this);
        if(Cleaning.report()==3){
          flagC=true;
        }
    	
    }
    
    public void process(MaintenanceEmployee Maintenance) {
    	
    	Maintenance.workOn(this);
        internalEquip.process(Maintenance);
        if(Maintenance.report()==2){
          flagM=true;
        }
    	
    }
    
   public boolean isFlagC() {
		return flagC;
	}

	public boolean isFlagM() {
		return flagM;
	}

	public boolean isFlagS() {
		return flagS;
	}

	public EquipmentCompartment getInternalEquip() {
		return internalEquip;
	}

public boolean ready_check(){
	    boolean temp= flagM&&flagS&&flagC&&internalEquip.ready_check();
	    if(temp) {
	      System.out.println( "CargoBay OK! \n");
	    }
	    else {
		   System.out.println( "CargoBay not OK! \n");
	    }
	    return temp;
	}
    
    public String toString() {
        String str ="\n\n |CargoCompartment| \n"+"flagM:"+String.valueOf(flagM)+"\n"+"flagS:"+String.valueOf(flagS)+"\n"+"\t ***Equipment(within)****:"+internalEquip.toString();

        return str;
    	  
    }
}


