library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity kurklu_lab1 is
	port(
		clk : in std_logic := '0';
		reset_n : in std_logic :='0';
		buttons : in  std_logic_vector(1 downto 0);
		sw  : in  std_logic_vector(9 downto 0);
		led : out std_logic_vector(7 downto 0));
end entity kurklu_lab1;

architecture rit of kurklu_lab1 is
	component kurklu_lab1_sys is
        port (
            clk_clk                            : in  std_logic                    := 'X';             -- clk
            reset_reset_n                      : in  std_logic                    := 'X';             -- reset_n
            led_external_connection_export     : out std_logic_vector(7 downto 0);                    -- export
            buttons_external_connection_export : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
            sw_external_connection_export      : in  std_logic_vector(9 downto 0) := (others => 'X')  -- export
        );
    end component kurklu_lab1_sys;

begin
	u0 : component kurklu_lab1_sys
        port map (
            clk_clk                            => clk,                            --                         clk.clk
            reset_reset_n                      => reset_n,                      --                       reset.reset_n
            led_external_connection_export     => led,     --     led_external_connection.export
            buttons_external_connection_export => buttons, -- buttons_external_connection.export
            sw_external_connection_export      =>  sw      --      sw_external_connection.export
        );
		  
end architecture;
