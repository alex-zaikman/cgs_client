using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;


namespace asz
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            try
            {
                //get local config
                string localConfigPath = Util.getCurrentPath() + "config.asz";
                Dictionary<string, string> localConfig = Util.readLocalConfig(localConfigPath);
                //get remote config
                Dictionary<string, string> remoteConfig = Util.readRemoteConfig(localConfig["updateserver"] + "/config.asz");
                if (Convert.ToInt32(localConfig["versionnum"]) < Convert.ToInt32(remoteConfig["versionnum"]))
                {
                    //ask user to update
                    DialogResult res = Util.raiseYesNo("new vertion founs", "new vertion of CGS found\nplease update");
                    switch (res)
                    {
                        case DialogResult.Yes:
                            Application.EnableVisualStyles();
                            Application.SetCompatibleTextRenderingDefault(false);
                            Application.Run(new CGS());

                            break;
                        case DialogResult.No:
                        default:
                            break;

                    }


                }

            }
            catch (Exception e)
            {

            }
            finally
            {
                //run cef proccess
                Process.Start("cgsclient.exe");
            }

        }
    }
}
