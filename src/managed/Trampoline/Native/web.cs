using System.Runtime.InteropServices;

namespace Mjcheetham.Trampoline.Native
{
    public static class web
    {
        private const string Library = "libtramp-web";

        [DllImport(Library, CallingConvention = CallingConvention.Cdecl)]
        public static extern int tramp_webview_show(byte[] start_url);
    }
}
