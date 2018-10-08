import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class pitest {

	private static pi pi = new pi();

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void testarchimedes() {
		pi.archimedes(Math.PI);
		assertEquals(12,pi.getResult() );
	}
	@Test
	public void testleibniz() {
		pi.leibniz(1);
		assertEquals(12,pi.getResult() );
	}
	@Test
	public void testwallis() {
		pi.wallis(Math.PI);
		assertEquals(12,pi.getResult() );
	}
	@Test
	public void testmonteCarlo() {
		pi.monteCarlo(Math.PI);
		assertEquals(12,pi.getResult() );
	}

}
