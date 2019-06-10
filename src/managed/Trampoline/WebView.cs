namespace Mjcheetham.Trampoline
{
    public class WebView
    {
        private readonly string _startUrl;

        public WebView(string startUrl)
        {
            _startUrl = startUrl;
        }

        public int Show()
        {
            return Native.web.tramp_webview_show(Utf8Converter.ToCString(_startUrl));
        }
    }
}
