package model;

import org.jetbrains.annotations.NotNull;

public class Person implements AbsorbedObject {
    private final String name;
    private final double weight;
    private boolean isAbsorbed = false;
    private PersonCondition condition = PersonCondition.AllRight;

    public Person(@NotNull String name, double weight){
        if (weight <= 0) throw new IllegalArgumentException();
        this.weight = weight;
        this.name = name;
    }

    @Override
    public boolean isAbsorbed() {
        return isAbsorbed;
    }

    @Override
    public double getMatterSize() {
        return weight * 1e23;
    }

    @Override
    public void onAbsorb(double force) {
        isAbsorbed = true;
        applyForce(force);
    }

    private void applyForce(double force){
        condition = (force < 30)
                ? PersonCondition.LittleJolt
                : (force < 100)
                    ? PersonCondition.FlewOutLikeConfetti
                    : PersonCondition.RippedToPieces;
    }

    public PersonCondition getCondition() {
        return condition;
    }

    public String getName() {
        return name;
    }

    public enum PersonCondition{
        AllRight,
        LittleJolt,
        FlewOutLikeConfetti,
        RippedToPieces,
    }
}
