using System.Text;

namespace Mjcheetham.Trampoline
{
    public static class Utf8Converter
    {
        private static readonly Encoding s_toCStr = new UTF8Encoding(false);
        private static readonly Encoding s_fromCStr = new UTF8Encoding(true);

        public static byte[] ToCString(string str)
        {
            return s_toCStr.GetBytes(str);
        }

        public static unsafe string FromCString(byte* ptr, int count)
        {
            return s_fromCStr.GetString(ptr, count);
        }

        public static unsafe string FromCString(byte[] data)
        {
            return s_fromCStr.GetString(data);
        }
    }
}
