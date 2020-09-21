package model;

import org.jetbrains.annotations.NotNull;
import tree.BTree;
import tree.Tree;

import java.awt.*;
import java.util.Collection;
import java.util.Iterator;
import java.util.Spliterator;
import java.util.function.Consumer;

public class Void<T extends Comparable<T>> implements Iterable<T> {
    private final Color color = Color.BLACK;
    private final Tree<T> elements = new BTree<>();

    public void sowElement(@NotNull T element){
        elements.add(element);
    }

    public boolean isSowed(){
        return elements.size() > 10;
    }

    public void suckAnObject(@NotNull AbsorbedObject object){
        double f = calculateForce(object.getMatterSize());
        object.onAbsorb(f);
    }

    private double calculateForce(double matterSize){
        return matterSize * 1.35e-23;
    }

    public Collection<T> getElements() {
        return elements.getCollection();
    }

    public Color getColor() {
        return color;
    }

    @Override
    public Iterator<T> iterator() {
        return getElements().iterator();
    }

    @Override
    public void forEach(Consumer<? super T> action) {
        getElements().forEach(action);
    }

    @Override
    public Spliterator<T> spliterator() {
        return getElements().spliterator();
    }
}
