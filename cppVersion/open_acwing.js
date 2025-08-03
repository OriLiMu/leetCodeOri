const puppeteer = require('puppeteer');

async function openAcWing() {
  const browser = await puppeteer.launch({
    headless: false, // Set to false to see the browser window
    defaultViewport: null,
    args: ['--start-maximized']
  });

  try {
    const page = await browser.newPage();
    
    // Set user agent to avoid detection
    await page.setUserAgent('Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36');
    
    console.log('Opening https://www.acwing.com/activity/content/31/...');
    await page.goto('https://www.acwing.com/activity/content/31/', {
      waitUntil: 'networkidle2',
      timeout: 30000
    });
    
    console.log('Page loaded successfully!');
    
    // Wait a bit for any dynamic content to load
    await page.waitForTimeout(3000);
    
    // Take a screenshot to verify it loaded correctly
    await page.screenshot({ path: 'acwing_page.png', fullPage: true });
    console.log('Screenshot saved as acwing_page.png');
    
    // Keep browser open for 30 seconds so you can see it
    await new Promise(resolve => setTimeout(resolve, 30000));
    
  } catch (error) {
    console.error('Error:', error.message);
  } finally {
    await browser.close();
  }
}

openAcWing();