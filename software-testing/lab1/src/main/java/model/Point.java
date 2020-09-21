package model;

public class Point implements Comparable<Point> {
    private final byte brightness;
    private boolean isShiny;

    public Point(byte brightness){
        if (brightness < 0) throw new IllegalArgumentException();
        this.brightness = brightness;
        this.isShiny = true;
    }

    public BrightnessType getBrightness(){
        if (!isShiny) return BrightnessType.None;

        if (brightness < 30) return BrightnessType.Low;
        else if (brightness < 60) return BrightnessType.Middle;
        else if (brightness < 90) return BrightnessType.High;
        else return BrightnessType.IncrediblyHigh;
    }

    @Override
    public int compareTo(Point o) {
        return getBrightness().compareTo(o.getBrightness());
    }

    public boolean isShiny() {
        return isShiny;
    }

    public enum BrightnessType {
        None,
        Low,
        Middle,
        High,
        IncrediblyHigh,
    }
}