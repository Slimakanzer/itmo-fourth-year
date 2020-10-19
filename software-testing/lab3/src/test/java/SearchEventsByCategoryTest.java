import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.util.List;
import java.util.concurrent.TimeUnit;

import static org.junit.Assert.assertEquals;

public class SearchEventsByCategoryTest extends SeleniumTest{
    public static final String CAREER_EVENT = "Career & Business events";
    public static final String OUTDOOR_EVENT = "Outdoors & Adventure events";
    public static final String LEARNING_EVENT = "Learning events";
    public static final String TECH_EVENT = "Tech events";
    public static final String FAMILY_EVENT = "Family events";
    public static final String HEALTH_EVENT = "Health & Wellness events";
    public static final String SPORT_EVENT = "Sports & Fitness events";
    public static final String FASHION_EVENT = "Fashion & Beauty events";
    public static final String SOCIAL_EVENT = "Social events";
    public static final String NO_EVENT_ERROR = "Sorry, there are no events near you.";

    private int getEventsSize(){
        waitUntilReady("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]");
        return driver.findElements(By.xpath("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/div/div[1]/div")).size();
    }

    private WebElement getCategoryButton(int id) {
        return waitUntilClickable("//*[@id=\"gatsby-focus-wrapper\"]/div[1]/div/div[6]/div[2]/section/div[1]/div[%d]/a".formatted(id));
    }

    private void clickEventMainPage(String id) {
        waitUntilClickable("//*[@id=\"%s\"]/div[1]//a".formatted(id)).click();
    }

    private void waitEvents(){
        driver.manage().timeouts().implicitlyWait(TIMEOUT, TimeUnit.SECONDS);
    }

    private String getSearchName(){
        return waitUntilReady("//*[@id=\"gatsby-focus-wrapper\"]/div[3]/div[2]/main/h1").getText();
    }

    @Test
    public void searchEventsCareerAndBusinessMainPage(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        clickEventMainPage("career");
        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(CAREER_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsOutdoorsAndAdventuresMainPage(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        clickEventMainPage("outdoors");
        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(OUTDOOR_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsLearningMainPage(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        clickEventMainPage("learning");
        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(LEARNING_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsTechMainPage(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        clickEventMainPage("tech");
        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(TECH_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsOutdoorsAndAdventuresMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(1).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(OUTDOOR_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsTechMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(2).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(TECH_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsFamilyMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(3).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(FAMILY_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsHealthMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(4).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(HEALTH_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsSportsMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(5).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(SPORT_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsLearningMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(6).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(LEARNING_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsFashionMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(22).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(FASHION_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsSocialMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(23).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(SOCIAL_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }

    @Test
    public void searchEventsCareerMainPageButton(){
        driver.get(URL);
        driver.manage().window().setSize(new Dimension(945, 1020));

        getCategoryButton(24).click();

        waitEvents();
        var eventsSize = getEventsSize();
        var searchName = getSearchName();

        if (eventsSize > 0) assertEquals(CAREER_EVENT, searchName);
        else assertEquals(NO_EVENT_ERROR, searchName);
    }
}
