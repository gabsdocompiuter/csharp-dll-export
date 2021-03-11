using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using RGiesecke.DllExport;

namespace exemplo
{
    public static class Class1
    {
        private static int number1;
        private static int number2;

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void AllocTwoNumbers(int n1, int n2)
        {
            number1 = n1;
            number2 = n2;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void GetSum(out int resultado)
        {
            resultado = number1 + number2;
        }

        [DllExport(CallingConvention = System.Runtime.InteropServices.CallingConvention.Cdecl)]
        public static void ShowError(string msgErro)
        {
            MessageBox.Show(msgErro, "Erro", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
