package model;

public final class Air implements AbsorbedObject {
    private static final double AirDensity = 1.2754; // кг/м^3
    private final double weight;
    private AirState currentState;
    private boolean isAbsorbed = false;

    public Air(double volume){
        if (volume <= 0) throw new IllegalArgumentException();
        weight = volume * AirDensity;
        currentState = AirState.SubtleHiss;
    }

    private void growUp(double force){
        currentState = (Math.abs(force) > 10) ? AirState.Roar : AirState.SubtleHiss;
    }

    public AirState getState() {
        return currentState;
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
        growUp(force);
    }
}
