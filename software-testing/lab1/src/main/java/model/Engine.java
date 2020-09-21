package model;

public class Engine {
    private boolean hummed;

    public void start(){
        hummed = true;
    }

    public boolean isHummed() { // мотор зажжужал?
        return hummed;
    }
}
