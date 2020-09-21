import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import tree.BTree;
import tree.Tree;

import java.util.stream.IntStream;

public class BTreeTest {
    private Tree<Integer> bTree;

    @Before
    public void setUp(){
        bTree = new BTree<>(2);
    }

    public void setUpBeforeFirstSplit(){
        setUpRange(1, 5);
    }

    public void setUpRange(int a, int b){
        IntStream.range(a, b).forEach(i -> bTree.add(i));
    }

    @Test
    public void testEmptyTree(){
        Assert.assertEquals(0, bTree.height());
        Assert.assertEquals(0, bTree.size());
        Assert.assertEquals("()", bTree.toString());
    }

    @Test
    public void testPutOneKey(){
        bTree.add(1);

        Assert.assertEquals(0, bTree.height());
        Assert.assertEquals(1, bTree.size());
        Assert.assertEquals("(1)", bTree.toString());
    }

    @Test
    public void testPutBeforeFirstSplit(){
        bTree.add(1);
        Assert.assertEquals(0, bTree.height());
        Assert.assertEquals(1, bTree.size());
        Assert.assertEquals("(1)", bTree.toString());

        bTree.add(2);
        Assert.assertEquals(0, bTree.height());
        Assert.assertEquals(2, bTree.size());
        Assert.assertEquals("(1, 2)", bTree.toString());

        bTree.add(3);
        Assert.assertEquals(0, bTree.height());
        Assert.assertEquals(3, bTree.size());
        Assert.assertEquals("(1, 2, 3)", bTree.toString());

        bTree.add(4);
        Assert.assertEquals(0, bTree.height());
        Assert.assertEquals(4, bTree.size());
        Assert.assertEquals("(1, 2, 3, 4)", bTree.toString());

    }

    @Test
    public void testPutAfterFirstSplit(){
        setUpBeforeFirstSplit();
        String internalRepresentationBeforeSplit = bTree.toString();
        int heightBeforeSplit = bTree.height();

        bTree.add(5);

        Assert.assertEquals(1, bTree.height());
        Assert.assertNotEquals(heightBeforeSplit, bTree.height());
        Assert.assertEquals(5, bTree.size());

        Assert.assertEquals("(3 (1, 2)(4, 5))", bTree.toString());
        Assert.assertNotEquals(internalRepresentationBeforeSplit, bTree.toString());
    }

    @Test
    public void testHeightWithManyNodes(){
        setUpRange(1, 100);

        Assert.assertEquals(3, bTree.height());
        Assert.assertEquals(99, bTree.size());
    }

    @Test
    public void testPutDuplicatedKeys(){
        setUpBeforeFirstSplit();

        bTree.add(2);
        Assert.assertEquals("(2 (1, 2)(3, 4))", bTree.toString());
        Assert.assertEquals(5, bTree.size());
        Assert.assertEquals(1, bTree.height());

        bTree.add(2);
        Assert.assertEquals("(2 (1, 2, 2)(3, 4))", bTree.toString());
        Assert.assertEquals(6, bTree.size());
        Assert.assertEquals(1, bTree.height());

        bTree.add(2);
        Assert.assertEquals("(2 (1, 2, 2, 2)(3, 4))", bTree.toString());
        Assert.assertEquals(1, bTree.height());
        Assert.assertEquals(7, bTree.size());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testTryPutInvalidKey(){
        bTree.add(null);
    }

    @Test
    public void testDeleteKeyBeforeSplit(){
        setUpBeforeFirstSplit();

        Assert.assertEquals(Integer.valueOf(2), bTree.remove(2));
        Assert.assertEquals(3, bTree.size());
        Assert.assertEquals("(1, 3, 4)", bTree.toString());
    }

    @Test
    public void testDeleteKeyAfterSplit(){
        setUpRange(1, 6);
        String internalRepresentationAfterSplit = bTree.toString();
        int heightAfterSplit = bTree.height();

        Assert.assertEquals(Integer.valueOf(2), bTree.remove(2));

        Assert.assertEquals(0, bTree.height());
        Assert.assertNotEquals(heightAfterSplit, bTree.height());
        Assert.assertEquals("(1, 3, 4, 5)", bTree.toString());
        Assert.assertNotEquals(internalRepresentationAfterSplit, bTree.toString());
    }

    @Test
    public void testDeleteNonexistentKey(){
        setUpRange(1, 100);
        String internalRepresentationBeforeDeletionKeys = bTree.toString();

        IntStream.range(101, 1001).forEach(i -> Assert.assertNull(bTree.remove(i)));
        Assert.assertEquals(internalRepresentationBeforeDeletionKeys, bTree.toString());
    }

    @Test
    public void testClearKeys(){
        setUpRange(1, 100);
        String internalRepresentationBeforeClear = bTree.toString();
        int heightBeforeClear = bTree.height();
        int sizeBeforeClear = bTree.size();

        bTree.clear();

        Assert.assertEquals(0, bTree.height());
        Assert.assertNotEquals(heightBeforeClear, bTree.height());

        Assert.assertEquals("()", bTree.toString());
        Assert.assertNotEquals(internalRepresentationBeforeClear, bTree.toString());

        Assert.assertEquals(0, bTree.size());
        Assert.assertNotEquals(sizeBeforeClear, bTree.size());
    }

    @Test
    public void testContainsExistentKeys(){
        setUpRange(1, 100);

        IntStream.range(1, 100).forEach(i -> Assert.assertTrue(bTree.contains(i)));
    }

    @Test
    public void testContainsNonexistentKeys(){
        setUpRange(1, 100);

        IntStream.range(101, 1001).forEach(i -> Assert.assertFalse(bTree.contains(i)));
    }
}
