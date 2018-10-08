package programming;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class SpeacialNumbersTest {

	private static SpeacialNumbers speacialnumbers = new SpeacialNumbers();
	
	
	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void testBellNumber() {
		speacialnumbers.BellNumber(7);
		assertEquals(877,speacialnumbers.getResult() );
	}

	@Test
	public void testTriangleNumber() {
		speacialnumbers.TriangleNumber(7);
		assertEquals(28,speacialnumbers.getResult() );
	}

	@Test
	public void testCatalanNumber() {
		speacialnumbers.CatalanNumber(7);
		assertEquals(429,speacialnumbers.getResult() );
	}

}
