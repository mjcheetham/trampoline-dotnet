using System;
using Mjcheetham.Trampoline;

namespace TestApp
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            var webView = new WebView("https://www.google.co.uk");
            int value = webView.Show();
            Console.WriteLine(value);
        }
    }
}
