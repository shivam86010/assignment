import React, { useEffect } from 'react';
import { useState } from 'react';
import { Box, Card, CardContent, Typography, Avatar, Grid, TextField, IconButton, Table, TableBody, TableCell, TableContainer, TableHead, TableRow, Paper, Button } from '@mui/material';
import SearchIcon from '@mui/icons-material/Search';
import avatar1 from '../../assets/avtar1.jpg'
import avatar2 from '../../assets/avtar2.jpg';
import avatar3 from '../../assets/avtar3.jpg';
import avatar4 from '../../assets/avtar4.jpg';
import excelFile from '../../assets/Trading_Data.xlsx';
import * as XLSX from "xlsx";

function Leaderboard() {
    const [ excelData, setExcelData ] = useState([]);
    const [ mostActive, setMostActive ] = useState(false);

    useEffect(() => {
        let handleFile;
        try{
            handleFile = async(event) => {
                const file =  await fetch(excelFile);
                const blob = await file.blob();
            
                const fileReader = new FileReader();
                fileReader.onload = (e) => {
                const data = new Uint8Array(e.target.result);
                const workbook = XLSX.read(data, { type: "array" });

                // Get the first sheet name
                const firstSheetName = workbook.SheetNames[0];

                // Get the worksheet
                const worksheet = workbook.Sheets[firstSheetName];

                // Convert worksheet to JSON
                const jsonData = XLSX.utils.sheet_to_json(worksheet, { header: 2 });
                console.log(jsonData.sort((a, b) => a[7]-b[7]));
                // console.log(JSON.(jsonData))
                setExcelData(jsonData); // Store the parsed data in state
                };

                fileReader.readAsArrayBuffer(blob);
                return true;
            }
        }catch(error){
            console.log(error);
            return false;
        }
        handleFile().then((stat) => {
            if(stat){
                excelData.sort((a, b) => a[7]-b[7]);
            }
        });
  
    }, []);

    useEffect(() => {
        if(excelData.length !== 0){
            const storeCount = { };
            // const ans = {};
            for(let data of excelData){
                storeCount[data.Name] = (storeCount[data.Name] || 0) + 1;
            }
            console.log(storeCount);
            const sortedArray = Object.entries(storeCount).sort((a, b) => a[1] - b[1]);
            console.log(sortedArray);
            setMostActive(sortedArray[sortedArray.length - 1]);
        }
    }, [excelData])

    const avatarImagesList = [ avatar1, avatar2, avatar3, avatar4 ];
  return (
    <Box sx={{ padding: 4, backgroundColor: '#f9fafb' }}>
      {/* Search Bar */}
      <Box sx={{ display: 'flex', alignItems: 'center', mb: 4 }}>
        <TextField
          placeholder="Start typing Ticker name, User, or Trader..."
          variant="outlined"
          fullWidth
          InputProps={{
            endAdornment: (
              <IconButton>
                <SearchIcon />
              </IconButton>
            ),
          }}
        />
      </Box>

      {/* Top Champions Section */}
      <Typography variant="h4" align="center" sx={{ mb: 2 }}>Champions</Typography>
      <Grid container spacing={2} justifyContent="center">
        {/* Champion Cards */}
        {excelData && excelData.map(({ Name, Rank, Alerts, Trades, Avg_Gain }, index) => (
          index <= 2 && <Grid item xs={12} sm={6} md={4} key={index}>
            <Card sx={{ borderRadius: 4, textAlign: 'center', padding: 2 }}>
              <Avatar sx={{ width: 56, height: 56, mx: 'auto', mb: 2 }} src={avatarImagesList[index]} />
              <Typography variant="h6">{Name}</Typography>
              <Typography color="textSecondary">Rank: {Rank}</Typography>
              <Typography>Alerts: {Alerts} | Trades: {Trades} | Avg Gain: {Avg_Gain}</Typography>
              <Button variant='outlined'>Profile</Button>
            </Card>
          </Grid>
        ))}
      </Grid>

      {/* Statistics Section */}
      {<Box sx={{ display: 'flex', justifyContent: 'space-around', mt: 4 }}>
        <Card key='Most Tips Given' sx={{ display: 'flex', flexDirection: 'row', borderRadius: 2, padding: '12px 16px' }}>
            <Box sx={{ display: 'flex', alignItems: 'center', paddingRight: '1.2rem'}}>
                <Avatar src={avatarImagesList[0]} sx={{ width: 40, height: 40, mx: 'auto', mb: 1 }} />
            </Box>
            <Box sx={{ display: 'flex', flexDirection: 'column', paddingRight: '3rem' }}>
                <Typography sx={{ fontSize: '1rem'}}>Most Tips Given</Typography>
                <Typography variant='h6'>{mostActive ? mostActive[0] : ''}</Typography>
            </Box>
            <Typography variant="h5" sx={{ display: 'flex', alignItems: 'center', fontStyle: 'italic', fontWeight: 600}}>89</Typography>
        </Card>
        <Card key='Most Tips Given' sx={{ display: 'flex', flexDirection: 'row', borderRadius: 2, padding: '12px 16px' }}>
            <Box sx={{ display: 'flex', alignItems: 'center', paddingRight: '1.2rem'}}>
                <Avatar src={avatarImagesList[1]} sx={{ width: 40, height: 40, mx: 'auto', mb: 1 }} />
            </Box>
            <Box sx={{ display: 'flex', flexDirection: 'column', paddingRight: '3rem' }}>
                <Typography sx={{ fontSize: '1rem'}}>Most Active</Typography>
                <Typography variant='h6'>{mostActive ? mostActive[0] : ''}</Typography>
            </Box>
            <Typography variant="h5" sx={{ display: 'flex', alignItems: 'center', fontStyle: 'italic', fontWeight: 600}}>{mostActive ? mostActive[1] : 0}</Typography>
        </Card>
        <Card key='Most Tips Given' sx={{ display: 'flex', flexDirection: 'row', borderRadius: 2, padding: '12px 16px' }}>
            <Box sx={{ display: 'flex', alignItems: 'center', paddingRight: '1.2rem'}}>
                <Avatar src={avatarImagesList[2]} sx={{ width: 40, height: 40, mx: 'auto', mb: 1 }} />
            </Box>
            <Box sx={{ display: 'flex', flexDirection: 'column', paddingRight: '3rem' }}>
                <Typography sx={{ fontSize: '1rem'}}>Longest Streaks</Typography>
                <Typography variant='h6'>{(excelData.sort((a, b) => a[4]-b[4]))[0]?.Name}</Typography>
            </Box>
            <Typography variant="h5" sx={{ display: 'flex', alignItems: 'center', fontStyle: 'italic', fontWeight: 600}}>{(excelData.sort((a, b) => a[4]-b[4]))[0]?.Streaks}</Typography>
        </Card>
        <Card key='Most Tips Given' sx={{ display: 'flex', flexDirection: 'row', borderRadius: 2, padding: '12px 16px' }}>
            <Box sx={{ display: 'flex', alignItems: 'center', paddingRight: '1.2rem'}}>
                <Avatar src={avatarImagesList[3]} sx={{ width: 40, height: 40, mx: 'auto', mb: 1 }} />
            </Box>
            <Box sx={{ display: 'flex', flexDirection: 'column', paddingRight: '3rem' }}>
                <Typography sx={{ fontSize: '1rem'}}>Rank Change</Typography>
                <Typography variant='h6'>{mostActive ? mostActive[0] : ''}</Typography>
            </Box>
            <Typography variant="h5" sx={{ display: 'flex', alignItems: 'center', fontStyle: 'italic', fontWeight: 600}}>{mostActive ? mostActive[1] : ''}</Typography>
        </Card>
      </Box>}

      {/* Ranking Table */}
      <TableContainer component={Paper} sx={{ mt: 4 }}>
        <Table>
          <TableHead>
            <TableRow>
              {[ '', '', 'Name', 'Trophies', 'Rank', 'Streaks', 'Alerts', 'Trades', 'Avg Gain', 'Xscore'].map((heading, index) => (
                <TableCell key={heading} align={index === 3 ? 'start' : 'center'}>{heading}</TableCell>
              ))}
            </TableRow>
          </TableHead>
          <TableBody>
            { excelData.map(({Name, Trading_Style, Streaks, Alerts, Trades, Avg_Gain, Trophies, Xscore, Rank}, index) => (
              <TableRow key={index}>
                <TableCell>{index+1}</TableCell>
                <TableCell><Avatar src={avatarImagesList[index%4]} sx={{ width: 40, height: 40, mx: 'auto', mb: 1 }} /></TableCell>
                <TableCell align="center">{Name}</TableCell>
                <TableCell>{Trophies}</TableCell>
                <TableCell align="center">{Rank}</TableCell>
                <TableCell align="center">{Streaks}</TableCell>
                <TableCell align="center">{Alerts}</TableCell>
                <TableCell align="center">{Trades}</TableCell>
                <TableCell align="center">{Avg_Gain}</TableCell>
                <TableCell align="center">{Xscore}</TableCell>
                {/* <TableCell align="center">Xscore</TableCell> */}
              </TableRow>
            ))}
          </TableBody>
        </Table>
      </TableContainer>
    </Box>
  );
}

export default Leaderboard;