package model;

public interface AbsorbedObject {
    boolean isAbsorbed();
    double getMatterSize();
    void onAbsorb(double force);
}
